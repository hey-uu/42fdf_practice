/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:13:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

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

t_vec4	vec3_normalize(t_vec4 *v)
{
	t_vec4			u;
	const double	norm = vec3_norm(v);
	int				i;

	i = -1;
	while (++i < 3)
		u.v[i] = v->v[i] / norm;
	u.v[i] = v->v[i];
	return (u);
}
