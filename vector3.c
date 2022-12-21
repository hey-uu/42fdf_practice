/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 19:43:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec3_dot_product(t_vec4 *u, t_vec4 *v)
{
	u = v = 0;
	return (0);
}

t_vec4	*vec3_normalize(t_vec4 *u)
{
	u = 0;
	return (0);
}

double	vec3_norm(t_vec4 *u)
{
	double	res;

	res = u->x * u->x + u->y + u->y + u->z + u->z;
	return (sqrt(res));
}

double	vec3_outer_product(t_vec4 *u, t_vec4 *v)
{
	u = v = 0;
	return (0);
}
