/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 02:54:26 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 15:28:44 by hyeyun           ###   ########.fr       */
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
	
	m_srt = get_srt_matrix(obj->scale, &obj->orientation, &obj->position);
	printf("world_transformation: m_srt\n");
	mat4_print(&m_srt);
	*m_world = mat4_mul(&m_srt, m_world);
	printf("world_transformation: m_world\n");
	mat4_print(m_world);
}

void	camera_get_view_vectors(t_camera *cam)
{
	cam->dir = vec4_subtract(&cam->look_at, &cam->position);
	printf("camera view direction vector:\n");
	vec4_print(&cam->dir);
	cam->dir = vec3_normalize(&cam->dir);
	printf("normalized camera view direction vector:\n");
	vec4_print(&cam->dir);
	cam->up = vec4_gram_shmidt(&(t_vec4){{0, 0, 1, 0}}, &cam->dir);
	printf("camera view up vector:\n");
	vec4_print(&cam->up);
	cam->up = vec3_normalize(&cam->up);
	printf("normalized camera view up vector:\n");
	vec4_print(&cam->up);
	cam->side = vec4_outer_product(&cam->dir, &cam->up);
	printf("normalized camera view side vector:\n");
	vec4_print(&cam->side);
	printf("inner product side, up vector : %f\n", vec4_dot_product(&cam->up, &cam->side));
	printf("inner product side, dir vector : %f\n", vec4_dot_product(&cam->side, &cam->dir));
}

void	camera_set_isometric_view(t_camera *cam, int opt)
{
	const t_vec4	pos[8] = {{{CD, -CD, CD, 1}}, {{CD, CD, CD, 1}}, \
							{{-CD, CD, CD, 1}}, {{-CD, -CD, CD, 1}}};
	
	cam->position = pos[opt]; 
	cam->look_at = (t_vec4){{0, 0, 0, 1}};
	camera_get_view_vectors(cam);	
}

void	transform_view(t_camera *cam, t_mat4 *m_view)
{
	printf("cam position\n");
	vec4_print(&cam->position);
	*m_view = get_inv_tr_matrix(\
			&cam->dir, &cam->up, &cam->side, &cam->position);
	printf("transform view matrix\n");
	mat4_print(m_view);
}

void	transform_viewport(t_mat4 *m_viewport)
{
	*m_viewport = (t_mat4){{{1, 0, 0, (double)I_WIDTH / 2}, \
							{0, -1, 0, (double)I_HEIGHT / 2}, \
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

void    transform_vertex(t_data *data, t_vec4 **vertex, t_point **screen, t_mat4 *m)
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
			tem = mat4_vec_mul(m, &vertex[i][j]);
			//vec4_print(&tem);
			screen[i][j].x = round_to_int(tem.v[0]);
			screen[i][j].y = round_to_int(tem.v[1]);
			screen[i][j].z = round_to_int(tem.v[2]);
			screen[i][j].color = data->color[i][j];
		}
	}
}