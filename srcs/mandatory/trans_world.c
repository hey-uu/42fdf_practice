/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_world.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:32:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/25 16:04:40 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "fdf.h"
#include "vector.h"

void	init_object_location(t_world *world, t_map *map, int scale)
{
	const t_mat4	t_ro_re = {{{scale, 0, 0, -scale * map->w / 2}, \
							{0, scale, 0, -scale * map->h / 2}, \
							{0, 0, -scale, 0}, \
							{0, 0, 0, 1}}};

	init_object(map->w, map->h, &world->obj, map);
	transform_object(&t_ro_re, &world->obj, &world->obj, (t_vec3){{0, 0, 0}});
}

void	init_camera_location(t_world *world)
{
	world->cam = ft_malloc(NULL, sizeof(t_camera));
	world->cam->pos = (t_vec4){{300, 300, -300, 1}};
	world->cam->ori = (t_vec3){{atan(sqrt(2)), 0, -M_PI_4}};
	world->cam->dist = vec3_norm(&world->cam->pos);
}

void	init_transform_into_world(t_world *world, t_map *map)
{
	init_object_location(world, map, SCALE);
	init_camera_location(world);
}
