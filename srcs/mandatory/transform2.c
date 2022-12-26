/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:37:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/27 01:59:43 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "color.h"

void	transform_viewport(t_mat4 *m_viewport)
{
	*m_viewport = (t_mat4){{{1, 0, 0, (double)I_W / 2}, \
							{0, -1, 0, (double)I_H / 2}, \
							{0, 0, 1, 0}, \
							{0, 0, 0, 1}}};
}

int	round_to_int(double x)
{
	int	res;

	res = (int)(x * 10) % 10;
	if (res >= 5)
		return ((int)(x + 1));
	if (res <= -5)
 		return ((int)(x - 1));
	return ((int)x);
}

void    transform_vertex(t_data *data, t_vec4 **vtx, t_point **scr, t_mat4 *m)
{
	t_vec4	tem;
	int		i;
	int		j;
	
	i = -1;
	while (++i < data->h)
	{
		j = -1;
		while (++j < data->w)
		{
			tem = mat4_vec_mul(m, &vtx[i][j]);
			scr[i][j].x = round_to_int(tem.v[0]);
			scr[i][j].y = round_to_int(tem.v[1]);
			scr[i][j].color = data->color[i][j];
		}
	}
}

void	transform_axis(t_point axis[6][2], t_mat4 *m)
{
	static t_vec4	pts[6] = \
					{{{W_W, 0, 0, 1}}, {{0, W_H, 0, 1}}, {{0, 0, W_W, 1}}, \
					{{-W_W, 0, 0, 1}}, {{0, -W_H, 0, 1}}, {{0, 0, -W_W, 1}}};
	static int		color[6] = {RED, GREEN, BLUE, GREY, GREY, GREY};
	t_vec4			tem;
	int				i;

	tem = mat4_vec_mul(m, &(t_vec4){{0, 0, 0, 1}});
	i = -1;
	while (++i < 6)
	{
		axis[i][0].x = round_to_int(tem.v[0]);
		axis[i][0].y = round_to_int(tem.v[1]);
		axis[i][0].color = color[i];
	}
	i = -1;
	while (++i < 6)
	{
		tem = mat4_vec_mul(m, &pts[i]);
		axis[i][1].x = round_to_int(tem.v[0]);
		axis[i][1].y = round_to_int(tem.v[1]);
		axis[i][1].color = color[i];
	}
}

void	rotate(t_object *obj, double theta, int axis)
{
	const double	t[2] = {cos(theta), sin(theta)};
	t_mat4			rot;

	if (axis == 0)
		rot = (t_mat4){{{1, 0, 0, 0}, {0, t[0], t[1], 0}, \
						{0, -t[1], t[0], 0}, {0, 0, 0, 1}}};
	else if (axis == 1)
		rot = (t_mat4){{{t[0], 0, t[1], 0}, {0, 1, 0, 0}, \
						{-t[1], 0, t[0], 0}, {0, 0, 0, 1}}};
	else
		rot = (t_mat4){{{t[0], -t[1], 0, 0}, {t[1], t[0], 0, 0}, \
						{0, 0, 1, 0}, {0, 0, 0, 1}}};
	obj->orientation = mat4_mul(&rot, &obj->orientation);
}