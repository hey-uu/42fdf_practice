/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector4_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:52:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 06:52:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
