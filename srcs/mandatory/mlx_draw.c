/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:17:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 22:05:49 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

void	draw_low_line(const t_two_points *s, t_img *img)
{
	int	pos[2];
	int	diff;
	int	y_inc;
	int color;

	y_inc = 1;
	if (s->dy < 0)
		y_inc = -1;
	diff = (2 * s->abs_dy) - s->abs_dx;
	pos[0] = s->p->x;
	pos[1] = s->p->y;
	while (pos[0] <= s->q->x)
	{
		color = get_color(s->p, s->q, pos[0]);
		mlx_pixel_put_image(img, pos[0], pos[1], color);
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
	int color;

	x_inc = 1;
	if (s->dx < 0)
		x_inc = -1;
	diff = (2 * s->abs_dx) - s->abs_dy;
	pos[0] = s->p->x;
	pos[1] = s->p->y;
	while (pos[1] <= s->q->y)
	{
		color = get_color(s->p, s->q, pos[0]);
		mlx_pixel_put_image(img, pos[0], pos[1], color);
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

void	mlx_draw_object_on_image(t_point **scr, t_img *img, int h, int w)
{
	int	i;
	int	j;

	i = -1;
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			if (i != h - 1)
				mlx_draw_line(&scr[i][j], &scr[i + 1][j], img);
			if (j != w - 1)
				mlx_draw_line(&scr[i][j], &scr[i][j + 1], img);
		}
	}
}

void	mlx_draw_axis_on_image(t_point axis[6][2], t_img *img)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_draw_line(&axis[i][0], &axis[i][1], img);
	mlx_draw_line(&(t_point){0, 0, WHITE}, \
				&(t_point){0, I_H, WHITE}, img);
}