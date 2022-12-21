/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:32:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 20:42:32 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "world.h"
#include "matrix.h"
#include "vector.h"
#include <stdio.h>

void	place_object_in_world(t_world *world, t_map *map)
{
	const int	dx = map->w / 2;
	const int	dy = map->h / 2;
	int			i;
	int			j;

	world->obj = ft_malloc(NULL, sizeof(t_object));
	world->obj->pos = ft_malloc(NULL, sizeof(t_vec4 *) * map->h);
	j = 0;
	while (j < map->h)
	{
		world->obj->pos[j] = ft_malloc(NULL, sizeof(t_vec4) * map->w);
		i = 0;
		while (i < map->w)
		{
			world->obj->pos[j][i] = (t_vec4){i - dx, j - dy, map->pos[j][i], 1};
			i++;
		}
		j++;
	}
	world->obj->h = map->h;
	world->obj->w = map->w;
	world->obj->rot = (t_vec3){0, 0, 0};
}

void	init_camera(t_world *world)
{
	world->cam = ft_malloc(NULL, sizeof(t_camera));
	world->cam->pos = (t_vec4){CDIST, CDIST, CDIST, 1};
	world->cam->rot = (t_vec3){0, 0, 0};
	world->cam->dist = vec3_norm(&world->cam->pos);
}

void	transform_into_world(t_world *world, t_map *map)
{
	place_object_in_world(world, map);
	init_camera(world);
}
