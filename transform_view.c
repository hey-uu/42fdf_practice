/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_view.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:45:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 21:45:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "world.h"

void	init_view(t_world *world, t_view *view)
{
	int	i;
	int	j;

	// camera는 같은 변수 공간을 가르키도록
	view->cam = world->cam;
	// obj에는 world->obj의 복제본을 넣어야함
	view->obj = ft_malloc(NULL, sizeof(t_object));
	view->obj->pos = ft_malloc(NULL, sizeof(t_vec4 *) * world->obj->h);
	j = 0;
	while (j < world->obj->h)
	{
		i = 0;
		view->obj->pos[j] = ft_malloc(NULL, sizeof(t_vec4) * world->obj->w);
		while (i < world->obj->w)
		{
			view->obj->pos[j][i] = world->obj->pos[j][i];
			i++;
		}
		j++;
	}
	view->obj->h = world->obj->h;
	view->obj->w = world->obj->w;
	view->obj->rot = world->obj->rot;
}

void	transform_view(t_world *world, t_view *view)
{
	init_view(world, view);
	
}
