/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 12:04:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec3_norm(t_vec4 *u)
{
	double	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 3)
	{
		res += u->v[i] * u->v[i];
	}
	return (sqrt(res));
}

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

double	vec4_norm(t_vec4 *u)
{
	double	res;
	int		i;

	res = 0;
	i = -1;
	while (++i < 4)
		res += u->v[i] * u->v[i];
	return (sqrt(res));
}

t_vec4	vec4_normalize(t_vec4 *v)
{
	t_vec4			u;
	const double	norm = vec4_norm(v);
	int				i;

	i = -1;
	while (++i < 4)
		u.v[i] = v->v[i] / norm;
	return (u);
}

double	vec4_outer_product(t_vec4 *u, t_vec4 *v)
{
	u = v = 0;
	return (0);
}
