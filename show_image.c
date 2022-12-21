/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:17:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 20:46:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "world.h"

void	init_image(t_dev *dev, t_img *img)
{
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, I_WIDTH, I_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	project_to_image(t_view *view, t_img *img)
{
	int	i;
	int	j;

	j = -1;
	while (++j < view->obj->h)
	{
		i = -1;
		while (++i < view->obj->w)
		{
			printf("x : %d, y : %d, z : %d\n", \
			(int)view->obj->pos[j][i].x + I_WIDTH / 2, \
			(int)view->obj->pos[j][i].y + I_HEIGHT / 2, \
			(int)view->obj->pos[j][i].z);
			if (view->obj->pos[j][i].z > 0)
				my_mlx_pixel_put(img, \
				((int)view->obj->pos[j][i].x) * INTVL + I_WIDTH / 2, \
				((int)view->obj->pos[j][i].y) * INTVL + I_HEIGHT / 2, \
				0xff00ff);
			else
				my_mlx_pixel_put(img, \
				((int)view->obj->pos[j][i].x) * INTVL + I_WIDTH / 2, \
				((int)view->obj->pos[j][i].y) * INTVL + I_HEIGHT / 2, \
				0x00ff00);
		}
	}
}

void	show_projection_image(t_dev *dev, t_map *map, t_img *img)
{
	static t_world	world;
	static t_view	view;

	init_image(dev, img);
	transform_into_world(&world, map);
	transform_view(&world, &view);
	project_to_image(&view, img);
	mlx_put_image_to_window(dev->mlx, dev->win, img->img, M_WIDTH, 0);
}
