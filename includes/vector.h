/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 16:14:51 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/*-------------- STANDARD HEADERS ---------------*/
# include <math.h>
# include <stdio.h>

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

#endif