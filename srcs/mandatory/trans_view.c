/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:45:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:01:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"

int	round_to_int(double x)
{
	int	res;

	res = (int)(x * 10) % 10;
	if (res >= 5)
		return ((int)(x + 1));
	return ((int)x);
}

void	converse_screen_coord(t_object *obj, t_screen *scr)
{
	int	i;
	int	j;

	scr->w = obj->w;
	scr->h = obj->h;
	scr->p = ft_calloc(scr->h, sizeof(t_point *));
	i = -1;
	while (++i < scr->h)
	{
		scr->p[i] = ft_calloc(scr->w, sizeof(t_point));
		j = -1;
		while (++j < scr->w)
		{
			scr->p[i][j].x = \
			round_to_int(obj->pos[i][j].v[0]) + I_WIDTH / 2;
			scr->p[i][j].y = \
			round_to_int(obj->pos[i][j].v[1]) + I_HEIGHT / 2;
			scr->p[i][j].z = obj->pos[i][j].v[2];
		}
	}
}


void	init_transform_view(t_world *world, t_view *view)
{
	const t_mat4	inv_rot = inv_rot_mat(&world->cam->ori);
	const t_mat4	inv_trl = inv_transl_mat(&world->cam->pos);
	const t_mat4	view_mat = mat4_mul(&inv_rot, &inv_trl);
	// const t_mat4	view_mat2 = {{{1, 0, 0, 0}, {0, 1, 0, 0}, \
	// 	{0, 0, 1, 0}, {0, 0, 0, 1}}};


	view->cam = world->cam;
	init_object(world->obj.w, world->obj.h, &view->obj, 0);
	transform_object(\
		&view_mat, &world->obj, &view->obj, \
		(t_vec3){0, M_PI_2 - atan((double)1 / sqrt(2)), -M_PI_4});
	// transform_object(\
	// 	&view_mat2, &world->obj, &view->obj, \
	// 	(t_vec3){0, M_PI_2 - atan((double)1 / sqrt(2)), M_PI_4});
	converse_screen_coord(&view->obj, &view->scr);
}
