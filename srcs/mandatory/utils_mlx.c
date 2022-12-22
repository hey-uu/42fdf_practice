/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:29:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:28:17 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_dev(t_dev *dev)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, W_WIDTH, W_HEIGHT, TITLE);
}

void	init_image(t_dev *dev, t_img *img, int w, int h)
{
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
}

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_WIDTH || y >= I_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	update_frames(t_img *img)
{
	ft_memset(img->addr, 0, I_WIDTH * I_HEIGHT * img->bits_per_pixel / 8);
	mlx_put_image_to_window(img->dev->mlx, img->dev->win, img->img, M_WIDTH, 0);
	return (1);
}