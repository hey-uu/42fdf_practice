/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:46:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "matrix.h"

t_vec4	mat4_vec_mul(const t_mat4 *mat, t_vec4 *vec)
{
	t_vec4	res;
	int		i;

	i = -1;
	while (++i < 4)
	{
		res.v[i] = vec4_dot_product(\
		&(t_vec4){mat->m[i][0], mat->m[i][1], mat->m[i][2], mat->m[i][3]}, vec);
	}
	return (res);
}

t_mat4	mat4_mul(const t_mat4 *a, const t_mat4 *b)
{
	t_mat4	c;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c.m[i][j] = vec4_dot_product(\
			&(t_vec4){a->m[i][0], a->m[i][1], a->m[i][2], a->m[i][3]}, \
			&(t_vec4){b->m[0][j], b->m[1][j], b->m[2][j], b->m[3][j]});
		}
	}
	return (c);
}

t_mat4	rot_mat(t_vec3 *ori)
{
	const double	c[3] = {cos(ori->v[0]), cos(ori->v[1]), cos(ori->v[2])};
	const double	s[3] = {sin(ori->v[0]), sin(ori->v[1]), sin(ori->v[2])};
	t_mat4			rot;

	rot.m[0][0] = c[2] * c[1];
	rot.m[0][1] = c[2] * s[1] * s[0] - s[2] * c[0];
	rot.m[0][2] = c[2] * s[1] * c[0] + s[2] * s[0];
	rot.m[0][3] = 0;
	rot.m[1][0] = s[2] * c[1];
	rot.m[1][1] = s[2] * s[1] * s[0] + c[2] * c[0];
	rot.m[1][2] = s[2] * s[1] * c[0] - c[2] * s[0];
	rot.m[1][3] = 0;
	rot.m[2][0] = -s[1];
	rot.m[2][1] = c[1] * s[0];
	rot.m[2][2] = c[1] * c[0];
	rot.m[2][3] = 0;
	rot.m[3][0] = 0;
	rot.m[3][1] = 0;
	rot.m[3][2] = 0;
	rot.m[3][3] = 1;
	return (rot);
}

t_mat4	inv_rot_mat(t_vec3 *ori)
{
	const double	c[3] = {cos(ori->v[0]), cos(ori->v[1]), cos(ori->v[2])};
	const double	s[3] = {sin(ori->v[0]), sin(ori->v[1]), sin(ori->v[2])};
	t_mat4			inv_rot;

	inv_rot.m[0][0] = c[2] * c[1];
	inv_rot.m[1][0] = c[2] * s[1] * s[0] - s[2] * c[0];
	inv_rot.m[2][0] = c[2] * s[1] * c[0] + s[2] * s[0];
	inv_rot.m[3][0] = 0;
	inv_rot.m[0][1] = s[2] * c[1];
	inv_rot.m[1][1] = s[2] * s[1] * s[0] + c[2] * c[0];
	inv_rot.m[2][1] = s[2] * s[1] * c[0] - c[2] * s[0];
	inv_rot.m[3][1] = 0;
	inv_rot.m[0][2] = -s[1];
	inv_rot.m[1][2] = c[1] * s[0];
	inv_rot.m[2][2] = c[1] * c[0];
	inv_rot.m[3][2] = 0;
	inv_rot.m[0][3] = 0;
	inv_rot.m[1][3] = 0;
	inv_rot.m[2][3] = 0;
	inv_rot.m[3][3] = 1;
	return (inv_rot);
}

t_mat4	transl_mat(t_vec4 *shift)
{
	t_mat4	trl;
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			trl.m[i][j] = (i == j);
	}
	trl.m[0][3] = shift->v[0];
	trl.m[1][3] = shift->v[1];
	trl.m[2][3] = shift->v[2];
	trl.m[3][3] = 1;
	return (trl);
}

t_mat4	inv_transl_mat(t_vec4 *shift)
{
	t_mat4	inv_trl;
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			inv_trl.m[i][j] = (i == j);
	}
	inv_trl.m[0][3] = -shift->v[0];
	inv_trl.m[1][3] = -shift->v[1];
	inv_trl.m[2][3] = -shift->v[2];
	inv_trl.m[3][3] = 1;
	return (inv_trl);
}
