/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:50:31 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

/*-------------- STANDARD HEADERS ---------------*/
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

/*-------------- FUNCTION PROTOTYPES -------------*/

t_mat4	get_srt_matrix(double s, t_mat4 *r, t_vec4 *t);
t_mat4	get_inv_tr_matrix(t_vec4 *d, t_vec4 *u, t_vec4 *s, t_vec4 *p);
t_vec4	mat4_vec_mul(const t_mat4 *mat, t_vec4 *vec);
t_mat4	mat4_mul(const t_mat4 *a, const t_mat4 *b);

#endif