/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:41:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 01:52:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <math.h>
#include <stdlib.h>

typedef struct s_point
{
	double	x;
	double	y;
	int		color;
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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_trunc(double x)
{
	return (floor(x));
}

int	ft_round(double x)
{
	return (floor(x + 0.5));
}

double	frac(double x)
{
	return (x - floor(x));
}

double	invfrac(double x)
{
	return ( 1 - frac(x));
}

double	ft_abs(double a)
{
	if (a > 0)
		return (a);
	return (-a);
}

void	swap_x_y(t_point *p, t_point *q)
{
	int	tem;

	tem = p->x;
	p->x = p->y;
	p->y = tem;
	tem = q->x;
	q->x = q->y;
	q->y = tem;
}

void	swap_point(t_point *p, t_point *q)
{
	t_point	tem;

	tem = *p;
	*p = *q;
	*q = tem;
}

int	control_brightness(double brightness, int color)
{
	int	r, g, b;

	r = ((color >> 16) & 0xff) * brightness;
	printf("%d\n", r);
	g = ((color >> 8) & 0xff) * brightness;
	b = (color & 0xff) * brightness;

	return ((r << 16 | g << 8 | b));
}

int	get_color(const t_point *p, const t_point *q, int x)
{
	int	ratio;
	int	rgb[3];

	if (q->x == p->x)
		return (q->color);
	ratio = (q->x - x) * 1000 / (q->x - p->x);
	rgb[0] = (((p->color >> 16) & 0xff) * ratio + \
			((q->color >> 16) & 0xff) * (1000 - ratio)) / 1000;
	rgb[1] = (((p->color >> 8) & 0xff) * ratio + \
			((q->color >> 8) & 0xff) * (1000 - ratio)) / 1000;
	rgb[2] = (((p->color) & 0xff) * ratio + \
			((q->color) & 0xff) * (1000 - ratio)) / 1000;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	draw_line(t_point *p, t_point *q, t_img *img)
{
	double		tem;
	double		xd, yd, grad;
	double		length;
	double		xm, xy, xf, yf;
	double		xend, yend;
	double		xgap, ygap;
	double		xpxll, ypxll;
	double		bright1, bright2;
	int			x, y, ix1, ix2, iy1, iy2;
	char		c1, c2, c;

	xd = q->x - p->x;
	yd = q->y - p->y;
	printf("%f %f\n", xd, yd);
	if (ft_abs(xd) > ft_abs(yd))
	{
		if (p->x > q->x)
		{
			swap_point(p, q);
			xd = q->x - p->x;
			yd = q->y - p->y;
		}
		grad = yd / xd;
		// end point 1
		xend = ft_trunc(p->x + 0.5);
		yend = p->y + grad * (xend - p->x);
		xgap = invfrac(p->x + 0.5);
		ix1 = (int)xend;
		iy1 = (int)yend;
		bright1 = invfrac(yend) * xgap;
		bright2 = frac(yend) * xgap;
		printf("color : %x, brightness : %f\n", p->color, bright1);
		c1 = control_brightness(bright1, p->color);
		c2 = control_brightness(bright2, p->color);
		printf("control brightness : %x, %x\n", c1, c2);
		my_mlx_pixel_put(img, ix1, iy1, c1);
		my_mlx_pixel_put(img, ix1, iy1 + 1, c2);
		yf = yend + grad;
		// end point2
		xend = ft_trunc(q->x + 0.5);
		yend = q->y + grad * (xend - q->x);
		xgap = invfrac(q->y - 0.5);
		ix2 = (int)xend;
		iy2 = (int)yend;
		bright1 = invfrac(yend) * xgap;
		bright2 = frac(yend) * xgap;		
		c1 = control_brightness(bright1, q->color);
		c2 = control_brightness(bright2, q->color);
		my_mlx_pixel_put(img, ix2, iy2, c1);
		my_mlx_pixel_put(img, ix2, iy2 + 1, c2);
		// main loop
		for (int x = ix1 + 1 ; x <= ix2 - 1; x++)
		{
			bright1 = invfrac(yf);
			bright2 = frac(yf);
			c = get_color(p, q, x);
			c1 = control_brightness(bright1, c);
			c2 = control_brightness(bright2, c);
			my_mlx_pixel_put(img, x, (int)yf, c1);
			my_mlx_pixel_put(img, x, (int)yf + 1, c2);
			yf = yf + grad;
		}
	}

}

int	main(void)
{
	static t_dev	dev;
	static t_img	img;
	t_point	p = {100, 100, 0xff0000};
	t_point	q = {500, 400, 0x00ff00};

	init_dev(&dev);
	init_image(&dev, &img);
	draw_line(&p, &q, &img);
	mlx_put_image_to_window(dev.mlx, dev.win, img.img, 0, 0);
	mlx_loop(dev.mlx);
}
