/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:19:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 19:42:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

/*-------------- STANDARD HEADERS ---------------*/
# include <math.h>

/*------------- STRUCT DECLARATIONS --------------*/
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

/*-------------- FUNCTION PROTOTYPES -------------*/
double	vec4_norm(t_vec4 *u);
double	vec3_norm(t_vec4 *u);
#endif