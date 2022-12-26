/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 16:11:31 by hyeyun           ###   ########.fr       */
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

t_vec4	vec3_normalize(t_vec4 *v)
{
	t_vec4			u;
	const double	norm = vec3_norm(v);
	int				i;

	i = -1;
	while (++i < 3)
		u.v[i] = v->v[i] / norm;
	return (u);
}
