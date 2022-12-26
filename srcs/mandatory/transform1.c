/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:54:26 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/27 00:33:52 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    transform_world(t_object *obj, int h, int w, t_mat4 *m_world)
{
	t_mat4          m_srt;

	*m_world = (t_mat4){{{1, 0, 0, -(double)w/2}, \
						{0, -1, 0, (double)h/2}, \
						{0, 0, 1, 0}, \
						{0, 0, 0, 1}}};
	
	m_srt = get_srt_matrix(obj->scale, &obj->orientation, &obj->pos);
	*m_world = mat4_mul(&m_srt, m_world);
}

void	camera_get_view_vectors(t_camera *cam)
{
	cam->dir = vec4_subtract(&cam->look_at, &cam->pos);
	cam->dir = vec3_normalize(&cam->dir);
	cam->up = vec4_gram_shmidt(&(t_vec4){{0, 0, 1, 0}}, &cam->dir);
	cam->up = vec3_normalize(&cam->up);
	cam->side = vec4_outer_product(&cam->dir, &cam->up);
}

void	init_camera_to_isometric_view(t_camera *cam, int opt)
{
	const t_vec4	pos[8] = \
                    {{{CLEN, -CLEN, CLEN, 1}}, {{-CLEN, -CLEN, CLEN, 1}}, \
					{{-CLEN, CLEN, CLEN, 1}}, {{CLEN, CLEN, CLEN, 1}}, \
					{{CLEN, -CLEN, -CLEN, 1}}, {{-CLEN, -CLEN, -CLEN, 1}}, \
					{{-CLEN, CLEN, -CLEN, 1}}, {{CLEN, CLEN, -CLEN, 1}}};
	
	cam->pos = pos[opt]; 
	cam->look_at = (t_vec4){{0, 0, 0, 1}};
}

void	transform_view(t_camera *cam, t_mat4 *m_view)
{
	*m_view = get_inv_tr_matrix(\
			&cam->dir, &cam->up, &cam->side, &cam->pos);
}

void	transform(t_data *s, int opt)
{
	if (opt == CAM_CHANGE)
	{
		camera_get_view_vectors(&s->cam);
		transform_view(&s->cam, &s->m_view);
		s->m_show = mat4_mul(&s->m_viewport, &s->m_view);
	}
	else if (opt == OBJ_CHANGE)
	{
		transform_world(&s->obj, s->h, s->w, &s->m_world);
	}
	s->m = mat4_mul(&s->m_show, &s->m_world);
}
