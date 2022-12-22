/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:32:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:46:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "matrix.h"
#include "vector.h"

void	init_object_location(t_world *world, t_map *map, int scale)
{
	const t_mat4	t_ro_re = {{{scale, 0, 0, -scale * map->w / 2}, \
							{0, scale, 0, -scale * map->h / 2}, \
							{0, 0, -scale, 0}, \
							{0, 0, 0, 1}}};
	// const t_mat4	mat2 = {{{scale, 0, 0, 0}, {0, scale, 0, 0}, \
	// 	{0, 0, scale, 0}, {0, 0, 0, scale}}};

	init_object(map->w, map->h, &world->obj, map);
	transform_object(&t_ro_re, &world->obj, &world->obj, (t_vec3){0, 0, 0});
	// transform_object(&mat2, &world->obj, &world->obj, (t_vec3){0, 0, 0});
}

void	init_camera_location(t_world *world)
{
	world->cam = ft_malloc(NULL, sizeof(t_camera));
	world->cam->pos = (t_vec4){-CAMDIST, CAMDIST, CAMDIST, 1};
	world->cam->ori = (t_vec3){atan(sqrt(2)), 0, -M_PI_4};
	world->cam->dist = vec3_norm(&world->cam->pos);
}

void	init_transform_into_world(t_world *world, t_map *map)
{
	init_object_location(world, map, SCALE);
	init_camera_location(world);
}
