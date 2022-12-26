/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 04:14:45 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/27 02:00:31 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat4  get_srt_matrix(double s, t_mat4 *r, t_vec4 *t)
{
	return ((t_mat4){{{s * r->m[0][0], s * r->m[0][1], s * r->m[0][2], t->v[0]}, \
					{s * r->m[1][0], s * r->m[1][1], s * r->m[1][2], t->v[1]}, \
					{s * r->m[2][0], s * r->m[2][1], s * r->m[2][2], t->v[2]}, \
					{0, 0, 0, 1}}});
}

t_mat4  get_inv_tr_matrix(t_vec4 *d, t_vec4 *u, t_vec4 *s, t_vec4 *p)
{
	return ((t_mat4){{{s->v[0], s->v[1], s->v[2], -vec4_dot_product(s, p)}, \
					{u->v[0], u->v[1], u->v[2], -vec4_dot_product(u, p)}, \
					{-d->v[0], -d->v[1], -d->v[2], vec4_dot_product(d, p)}, \
					{0, 0, 0, 1}}});
}

t_vec4	mat4_vec_mul(const t_mat4 *mat, t_vec4 *vec)
{
	t_vec4	res;
	int		i;

	i = -1;
	while (++i < 4)
	{
		res.v[i] = vec4_dot_product(\
		&(t_vec4){{mat->m[i][0], mat->m[i][1], mat->m[i][2], mat->m[i][3]}}, vec);
	}
	return (res);
}

t_mat4	mat4_mul(const t_mat4 *a, const t_mat4 *b)
{
	t_mat4	c;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c.m[i][j] = vec4_dot_product(\
			&(t_vec4){{a->m[i][0], a->m[i][1], a->m[i][2], a->m[i][3]}}, \
			&(t_vec4){{b->m[0][j], b->m[1][j], b->m[2][j], b->m[3][j]}});
		}
	}
	return (c);
}
