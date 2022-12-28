/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:17:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/28 19:47:46 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

void	draw_low_line(const t_two_points *s, t_img *img)
{
	int	r[2];
	int	diff;
	int	y_inc;

	y_inc = 1;
	if (s->dy < 0)
		y_inc = -1;
	diff = (2 * s->abs_dy) - s->abs_dx;
	r[0] = s->p->x;
	r[1] = s->p->y;
	while (r[0] <= s->q->x)
	{
		mlx_pixel_put_image(img, r[0], r[1], get_color(s->p, s->q, r[0]));
		if (diff > 0)
		{
			r[1] += y_inc;
			diff += (2 * (s->abs_dy - s->abs_dx));
		}
		else
			diff += (2 * s->abs_dy);
		r[0] += 1;
	}
}

void	draw_high_line(const t_two_points *s, t_img *img)
{
	int	r[2];
	int	diff;
	int	x_inc;

	x_inc = 1;
	if (s->dx < 0)
		x_inc = -1;
	diff = (2 * s->abs_dx) - s->abs_dy;
	r[0] = s->p->x;
	r[1] = s->p->y;
	while (r[1] <= s->q->y)
	{
		mlx_pixel_put_image(img, r[0], r[1], get_color(s->p, s->q, r[0]));
		if (diff > 0)
		{
			r[0] += x_inc;
			diff += (2 * (s->abs_dx - s->abs_dy));
		}
		else
			diff += 2 * s->abs_dx;
		r[1] += 1;
	}
}

void	mlx_draw_line(const t_point *p, const t_point *q, t_img *img)
{
	const t_two_points	s1 = {p, q, q->x - p->x, q->y - p->y, \
							ft_abs(q->x - p->x), ft_abs(q->y - p->y)};
	const t_two_points	s2 = {q, p, p->x - q->x, p->y - q->y, \
							ft_abs(q->x - p->x), ft_abs(q->y - p->y)};
	int					c[2];

	c[0] = (p->x < 0) << 3 | (p->x > I_W) << 2 | (p->y < 0) << 1 | (p->y > I_H);
	c[1] = (q->x < 0) << 3 | (q->x > I_W) << 2 | (q->y < 0) << 1 | (q->y > I_H);
	if (c[0] & c[1])
		return ;
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

void	draw_object(t_point **scr, t_img *img, int h, int w)
{
	int			i;
	int			j;

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

void	draw_axis(t_point axis[6][2], t_img *img)
{
	int	i;

	i = -1;
	while (++i < 6)
		mlx_draw_line(&axis[i][0], &axis[i][1], img);
	mlx_draw_line(\
	&(t_point){0, 0, WHITE}, &(t_point){0, I_H, WHITE}, img);
}
