/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 12:54:46 by hyeyun           ###   ########.fr       */
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

t_vec4	vec4_subtract(t_vec4 *u, t_vec4 *v)
{
	t_vec4  w;
	int     i;

	i = -1;
	while (++i < 4)
	{
		w.v[i] = u->v[i] - v->v[i];
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

void    vec4_print(t_vec4 *u)
{
    for (int i = 0 ; i < 4 ; i++)
        printf("%f ", u->v[i]);
    printf("\n");
}