/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:50:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/*-------------- STANDARD HEADERS ---------------*/
# include <math.h>

/*------------- STRUCT DECLARATIONS --------------*/
typedef struct s_vec3
{
	double	v[3];
}	t_vec3;

typedef struct s_vec4
{
	double	v[4];
}	t_vec4;

/*-------------- FUNCTION PROTOTYPES -------------*/
// vector3
double	vec3_norm(t_vec4 *u);
t_vec4	vec3_normalize(t_vec4 *v);

// vector4
double	vec4_dot_product(t_vec4 *u, t_vec4 *v);
t_vec4	vec4_subtract(t_vec4 *u, t_vec4 *v);
t_vec4	vec4_scalar_mul(double alpha, t_vec4 *u);
t_vec4	vec4_gram_shmidt(t_vec4 *u, t_vec4 *v);
t_vec4	vec4_outer_product(t_vec4 *u, t_vec4 *v);
t_vec4	vec4_add(t_vec4 *u, t_vec4 *v);
int		vec4_equals(t_vec4 *u, t_vec4 *v);

#endif