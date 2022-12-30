/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:53:07 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 15:10:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transform_world(t_object *obj, int h, int w, t_mat4 *m_world)
{
	t_mat4	m_srt;

	*m_world = (t_mat4){\
			{{obj->t_scale[1], 0, 0, -(double)w / 2 * obj->t_scale[1]}, \
			{0, -obj->t_scale[2], 0, (double)h / 2 * obj->t_scale[2]}, \
			{0, 0, obj->t_scale[3], 0}, \
			{0, 0, 0, 1}}};
	m_srt = get_srt_matrix(obj->t_scale[0], &obj->orientation, &obj->t_pos);
	*m_world = mat4_mul(&m_srt, m_world);
}

void	camera_get_view_vectors(t_camera *cam)
{
	cam->dir = vec4_subtract(&cam->look_at, &cam->t_pos);
	if (cam->dir.v[0] == 0 && cam->dir.v[1] == 0)
		init_camera_to_top_view(cam, 1);
	else
	{
		cam->dir = vec3_normalize(&cam->dir);
		cam->up = vec4_gram_shmidt(&(t_vec4){{0, 0, 1, 0}}, &cam->dir);
		cam->up = vec3_normalize(&cam->up);
		cam->side = vec4_outer_product(&cam->dir, &cam->up);
	}
}

void	transform_view(t_camera *cam, t_mat4 *m_view)
{
	*m_view = get_inv_tr_matrix(\
			&cam->dir, &cam->up, &cam->side, &cam->t_pos);
}

void	transform(t_data *s, int opt)
{
	if (opt == OBJ_CHANGE)
	{
		transform_world(&s->obj, s->h - 1, s->w - 1, &s->m_world);
	}
	else if (opt == CAM_CHANGE)
	{
		camera_get_view_vectors(&s->cam);
		transform_view(&s->cam, &s->m_view);
		s->m_show = mat4_mul(&s->m_viewport, &s->m_view);
	}
	s->m = mat4_mul(&s->m_show, &s->m_world);
}

void	rotate(t_object *obj, double theta, int axis)
{
	const double	t[2] = {cos(theta), sin(theta)};
	t_mat3			rot;

	if (axis == 0)
		rot = (t_mat3){{{1, 0, 0}, {0, t[0], t[1]}, {0, -t[1], t[0]}}};
	else if (axis == 1)
		rot = (t_mat3){{{t[0], 0, t[1]}, {0, 1, 0}, {-t[1], 0, t[0]}}};
	else
		rot = (t_mat3){{{t[0], -t[1], 0}, {t[1], t[0], 0}, {0, 0, 1}}};
	obj->orientation = mat3_mul(&rot, &obj->orientation);
}
