/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:26:40 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/27 01:07:46 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

int get_vertex_color(int max, int min, int z)
{
	double  ratio;

	ratio = (double)(max - z) / (max - min);
	if (ratio < 0.2)
		return (YELLOW);
	if (ratio < 0.4)
		return (LIGHTGREEN);
	if (ratio < 0.6)
		return (MINT);
	if (ratio < 0.8)
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
			s->color[i][j] = get_vertex_color(s->max, s->min, (int)p[i][j].v[2]);
		}
	}
}

int get_color(const t_point *p, const t_point *q, int x)
{
	double	ratio;
	int		rgb[3];

	if (q->x == p->x)
		return (q->color);
	ratio = (double)(q->x - x) / (q->x - p->x);
	rgb[0] = ((p->color >> 16) & 0xff) * ratio + \
			((q->color >> 16) & 0xff) * (1 - ratio);
	rgb[1] = ((p->color >> 8) & 0xff) * ratio + \
			((q->color >> 8) & 0xff) * (1 - ratio);
	rgb[2] = ((p->color) & 0xff) * ratio + \
			((q->color) & 0xff) * (1 - ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}