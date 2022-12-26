/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:50:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:18:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

typedef struct s_dev
{
	void	*mlx;
	void	*win;
}	t_dev;

// data set for an image
typedef struct s_img
{
	t_dev	*dev;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_two_points
{
	const t_point	*p;
	const t_point	*q;
	int				dx;
	int				dy;
	int				abs_dx;
	int				abs_dy;
}	t_two_points;

typedef struct s_screen
{
	t_point	**p;
	int		w;
	int		h;
}	t_screen;

void	init_dev(t_dev *dev)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, 1920, 1080, "test");
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

	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_low_line(const t_two_points *s, t_img *img)
{
	int	pos[2];
	int	diff;
	int	y_inc;

	y_inc = 1;
	if (s->dy < 0)
		y_inc = -1;
	diff = (2 * s->abs_dy) - s->abs_dx;
	pos[0] = s->p->x;
	pos[1] = s->p->y;
	while (pos[0] <= s->q->x)
	{
		mlx_pixel_put_image(img, pos[0], pos[1], 0x00ff00);
		if (diff > 0)
		{
			pos[1] += y_inc;
			diff += (2 * (s->abs_dy - s->abs_dx));
		}
		else
			diff += (2 * s->abs_dy);
		pos[0] += 1;
	}
}

void	draw_high_line(const t_two_points *s, t_img *img)
{
	int	pos[2];
	int	diff;
	int	x_inc;

	x_inc = 1;
	if (s->dx < 0)
		x_inc = -1;
	diff = (2 * s->abs_dx) - s->abs_dy;
	pos[0] = s->p->x;
	pos[1] = s->p->y;
	while (pos[1] <= s->q->y)
	{
		mlx_pixel_put_image(img, pos[0], pos[1], 0x00ff00);
		if (diff > 0)
		{
			pos[0] += x_inc;
			diff += (2 * (s->abs_dx - s->abs_dy));
		}
		else
			diff += 2 * s->abs_dx;
		pos[1] += 1;
	}	
}

void	mlx_draw_line(const t_point *p, const t_point *q, t_img *img)
{
	const t_two_points	s1 = {p, q, q->x - p->x, q->y - p->y, \
							abs(q->x - p->x), abs(q->y - p->y)};
	const t_two_points	s2 = {q, p, p->x - q->x, p->y - q->y, \
							abs(q->x - p->x), abs(q->y - p->y)};

	if (s1.abs_dy < s1.abs_dx)
	{
		if (s1.dx < 0)
			draw_low_line(&s2, img);
		else
			draw_low_line(&s1, img);
	}
	else
	{
		if (s1.dy < 0)
			draw_high_line(&s2, img);
		else
			draw_high_line(&s1, img);
	}
}


void	project_to_image(t_screen *scr, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scr->h)
	{
		j = -1;
		while (++j < scr->w)
		{
			if (j != scr->w - 1)
			{
			printf("x%d%d : %d %d\n", i, j,scr->p[i][j].x, scr->p[i][j + 1].x);
			printf("y%d%d : %d %d\n", i, j,scr->p[i][j].y, scr->p[i][j + 1].y);
				mlx_draw_line(&scr->p[i][j], &scr->p[i][j + 1], img);
			}
			if (i != scr->h - 1)
			{
			printf("x%d%d : %d %d\n", i, j,  scr->p[i][j].x, scr->p[i + 1][j].x);
			printf("y%d%d : %d %d\n", i, j, scr->p[i][j].y, scr->p[i + 1][j].y);
				mlx_draw_line(&scr->p[i][j], &scr->p[i + 1][j], img);
			}
		}
	}
}

int main(void)
{
	t_dev		dev;
	t_img		img;
	t_screen	scr;

	scr.p = malloc(sizeof(t_point *) * 4);
	for (int i = 0 ; i < 4 ; i++)
	{
		scr.p[i] = malloc(sizeof(t_point) * 4);
		for (int j = 0 ; j < 4 ; j++)
		{
			scr.p[i][j].x = (4 * i + j) * 20;
			scr.p[i][j].y = j * 50;
		}
	}
	scr.h = 4;
	scr.w = 4;
	init_dev(&dev);
	init_image(&dev, &img, 1800, 1000);
	// project_to_image(&scr, &img);
	// mlx_put_image_to_window(dev.mlx, dev.win, img.img, 100, 100);
	// mlx_loop(&dev.mlx);

	t_point point1;
	t_point point2;
	point1 = (t_point){100, 100};
	point2 = (t_point){150, 0};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){200, 50};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){200, 150};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){150, 200};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){50, 200};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){0, 150};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){0, 50};
	mlx_draw_line(&point1, &point2, &img);
	point2 = (t_point){50, 0};
	mlx_draw_line(&point1, &point2, &img);
	mlx_put_image_to_window(dev.mlx, dev.win, img.img, 100, 100);
	mlx_loop(&dev.mlx);
}
