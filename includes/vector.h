/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 13:09:22 by hyeyukim         ###   ########.fr       */
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

// vector4
double	vec4_dot_product(t_vec4 *u, t_vec4 *v);
double	vec4_norm(t_vec4 *u);
#endif