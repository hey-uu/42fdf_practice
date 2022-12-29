/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:49:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/29 22:52:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec4_dot_product(t_vec4 *u, t_vec4 *v)
{
	double	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 4)
	{
		res += u->v[i] * v->v[i];
	}
	return (res);
}

t_vec4	vec4_subtract(t_vec4 *u, t_vec4 *v)
{
	t_vec4	w;
	int		i;

	i = -1;
	while (++i < 4)
	{
		w.v[i] = u->v[i] - v->v[i];
	}
	return (w);
}

t_vec4	vec4_add(t_vec4 *u, t_vec4 *v)
{
	t_vec4	w;
	int		i;

	i = -1;
	while (++i < 4)
	{
		w.v[i] = u->v[i] + v->v[i];
	}
	return (w);
}

t_vec4	vec4_scalar_mul(double alpha, t_vec4 *u)
{
	t_vec4	w;
	int		i;

	i = -1;
	while (++i < 4)
	{
		w.v[i] = alpha * u->v[i];
	}
	return (w);
}

t_vec4	vec4_gram_shmidt(t_vec4 *u, t_vec4 *unit_v)
{
	double	alpha;
	t_vec4	w;

	alpha = vec4_dot_product(u, unit_v);
	w = vec4_scalar_mul(alpha, unit_v);
	return (vec4_subtract(u, &w));
}

t_vec4	vec4_outer_product(t_vec4 *u, t_vec4 *v)
{
	return ((t_vec4){{u->v[1] * v->v[2] - u->v[2] * v->v[1], \
					u->v[2] * v->v[0] - u->v[0] * v->v[2], \
					u->v[0] * v->v[1] - u->v[1] * v->v[0]}});
}

int	vec4_equals(t_vec4 *u, t_vec4 *v)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (u->v[i] != v->v[i])
			return (0);
	}
	return (1);
}
