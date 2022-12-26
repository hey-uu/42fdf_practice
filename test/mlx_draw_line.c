/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:41:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 10:36:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dev
{
	void	*mlx;
	void	*win;
}	t_dev;

typedef struct s_img
{
	t_dev	*dev;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_two_points
{
	const t_point	*p;
	const t_point	*q;
	int				dx;
	int				dy;
	int				abs_dx;
	int				abs_dy;
}	t_two_points;

void	init_dev(t_dev *dev)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, 1920, 1080, "draw line");
}

void	init_image(t_dev *dev, t_img *img)
{
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
}

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


int	main(void)
{
	static t_dev	dev;
	static t_img	img;
	const t_point	p = {100, 100};
	const t_point	q = {100, 400};

	init_dev(&dev);
	init_image(&dev, &img);
	mlx_draw_line(&p, &q, &img);
	mlx_put_image_to_window(dev.mlx, dev.win, img.img, 0, 0);
	mlx_loop(dev.mlx);
}
