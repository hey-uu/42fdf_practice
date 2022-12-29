/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/29 23:10:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_camera_to_isometric_view(t_camera *cam, int opt)
{
	const t_vec4	pos[8] = \
					{{{CLEN, -CLEN, CLEN, 1}}, {{-CLEN, -CLEN, CLEN, 1}}, \
					{{-CLEN, CLEN, CLEN, 1}}, {{CLEN, CLEN, CLEN, 1}}, \
					{{CLEN, -CLEN, -CLEN, 1}}, {{-CLEN, -CLEN, -CLEN, 1}}, \
					{{-CLEN, CLEN, -CLEN, 1}}, {{CLEN, CLEN, -CLEN, 1}}};

	cam->pos = pos[opt];
	cam->t_pos = cam->pos;
	cam->look_at = (t_vec4){{0, 0, 0, 1}};
}

void	init_camera_to_top_view(t_camera *cam, int opt)
{
	if (!opt)
	{
		cam->pos = (t_vec4){{0, 0, 1, 1}};
		cam->t_pos = cam->pos;
		cam->look_at = (t_vec4){{0, 0, 0, 1}};
		return ;
	}
	if (cam->dir.v[2] > 0)
	{
		cam->dir = (t_vec4){{0, 0, 1, 0}};
		cam->up = (t_vec4){{0, -1, 0, 0}};
		cam->side = (t_vec4){{1, 0, 0, 0}};
		return ;
	}
	cam->dir = (t_vec4){{0, 0, -1, 0}};
	cam->up = (t_vec4){{0, 1, 0, 0}};
	cam->side = (t_vec4){{1, 0, 0, 0}};
}
