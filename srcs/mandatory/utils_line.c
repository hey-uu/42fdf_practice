/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:33:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:40:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		// for (int i = -2 ; i < 3 ; i++)
		// 	for (int j = -2 ; j < 3 ; j++)
		// 	{
		// 		mlx_pixel_put_image(img, s->q->x + i, s->q->y + j, 0xff0000);
		// 		mlx_pixel_put_image(img, s->p->x + i, s->p->y + j, 0xff0000);
		// 	}
	// if (s->p->z < 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->p->x + i, s->p->y + j, 0xff0000);
	// if (s->q->z < 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->q->x + i, s->q->y + j, 0xff0000);
	// if (s->p->z > 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->p->x + i, s->p->y + j, 0x0000ff);
	// if (s->q->z > 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->q->x + i, s->q->y + j, 0x0000ff);
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
	// if (s->p->z < 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->p->x + i, s->p->y + j, 0xff0000);
	// if (s->q->z < 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->q->x + i, s->q->y + j, 0xff0000);
	// if (s->p->z > 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->p->x + i, s->p->y + j, 0x0000ff);
	// if (s->q->z > 0)
	// 	for (int i = -1 ; i < 2 ; i++)
	// 		for (int j = -1 ; j < 2 ; j++)
	// 			mlx_pixel_put_image(img, s->q->x + i, s->q->y + j, 0x0000ff);
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
