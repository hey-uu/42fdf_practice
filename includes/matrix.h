/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 13:09:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/*-------------- STANDARD HEADERS ---------------*/
# include <stdio.h>
# include <math.h>

/*----------- DEFINE MACRO CONSTANTS ------------*/
# include "vector.h"

/*------------- STRUCT DECLARATIONS --------------*/
typedef struct s_mat3
{
	double	m[3][3];
}	t_mat3;

typedef struct s_mat4
{
	double	m[4][4];
}	t_mat4;

t_mat4	mat4_mul(const t_mat4 *a, const t_mat4 *b);
t_vec4	mat4_vec_mul(const t_mat4 *mat, t_vec4 *vec);
t_mat4	rot_mat(t_vec3 *ori);
t_mat4	transl_mat(t_vec4 *shift);
t_mat4	inv_rot_mat(t_vec3 *ori);
t_mat4	inv_transl_mat(t_vec4 *shift);
#endif