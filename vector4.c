/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 19:43:46 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec4_dot_product(t_vec4 *u, t_vec4 *v)
{
	u = v = 0;
	return (0);
}

t_vec4	*vec4_normalize(t_vec4 *u)
{
	u = 0;
	return (0);
}

double	vec4_norm(t_vec4 *u)
{
	double	res;

	res = u->x * u->x + u->y + u->y + u->z + u->z + u->w + u->w;
	return (sqrt(res));
}

double	vec4_outer_product(t_vec4 *u, t_vec4 *v)
{
	u = v = 0;
	return (0);
}
