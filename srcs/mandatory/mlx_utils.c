/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 13:36:21 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "keycode.h"

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_WIDTH || y >= I_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hooks(int key, t_data *data)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(data->dev.mlx, data->img.img);
		mlx_destroy_window(data->dev.mlx, data->dev.win);
		exit(0);
	}
	return (1);
}

int	render_next_frame(t_data *data)
{
	ft_memset(data->img.addr, 0, I_HEIGHT * I_WIDTH * data->img.bits_per_pixel / 8);
	transform_vertex(data, data->vertex, data->screen, &data->m);
	mlx_draw_object_on_image(data->screen, &data->img, data->h, data->w);
	mlx_draw_axis_on_image(&data->img);
    mlx_put_image_to_window(data->dev.mlx, data->dev.win, data->img.img, M_WIDTH, 0);
	return (0);
}

void	show_menu(t_dev *dev)
{
	mlx_string_put(dev->mlx, dev->win, 10, 10, 0xffffff, "==menu==");
}
