/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:26:40 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/28 17:20:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int	get_vertex_color(int max, int min, int z)
{
	int	ratio;

	if (max == min)
		return (MINT);
	ratio = (max - z) * 1000 / (max - min);
	if (ratio < 200)
		return (YELLOW);
	if (ratio < 400)
		return (LIGHTGREEN);
	if (ratio < 600)
		return (MINT);
	if (ratio < 800)
		return (SKYBLUE);
	return (PURPLE);
}

void	set_vertex_color(t_vec4 **p, t_data *s)
{
	int	i;
	int	j;

	s->color = ft_malloc(sizeof(int *) * s->h);
	i = -1;
	while (++i < s->h)
	{
		s->color[i] = ft_malloc(sizeof(int) * s->w);
		j = -1;
		while (++j < s->w)
		{
			s->color[i][j] = get_vertex_color(\
				s->max, s->min, (int)p[i][j].v[2]);
		}
	}
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

int	alpha_blending(int color1, int color2, int alpha)
{
	int	rgb[3];
	int	idx;
	int	mask;

	mask = 16;
	idx = -1;
	while (++idx < 3)
	{
		rgb[idx] = (((color1 >> mask) & 0xff) * alpha + \
				((color2 >> mask) & 0xff) * (100 - alpha)) / 1000;
		mask /= 2;
	}
	return ((rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]));
}
