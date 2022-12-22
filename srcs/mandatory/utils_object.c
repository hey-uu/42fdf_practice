/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:00:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 20:42:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_object(int w, int h, t_object *obj, t_map *map)
{
	int	i;
	int	j;

	obj->h = h;
	obj->w = w;
	obj->pos = ft_calloc(h, sizeof(t_vec4 *));
	i = -1;
	while (++i < h)
	{
		obj->pos[i] = ft_calloc(w, sizeof(t_vec4));
		if (map != 0)
		{
			j = -1;
			while (++j < w)
				obj->pos[i][j] = (t_vec4){j, i, map->pos[i][j], 1};
		}
	}
}

void	transform_object(\
		const t_mat4 *m, t_object *obj, t_object *dst, t_vec3 ori)
{
	int	i;
	int	j;

	i = -1;
	while (++i < obj->h)
	{
		j = -1;
		while (++j < obj->w)
		{
			dst->pos[i][j] = mat4_vec_mul(m, &obj->pos[i][j]);
			printf("%f %f %f\n", dst->pos[i][j].v[0], dst->pos[i][j].v[1], \
					dst->pos[i][j].v[2]);
		}
	}
	dst->ori = ori;
}
