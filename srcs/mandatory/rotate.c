/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:16:26 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/27 00:59:00 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_object *obj, double theta, int axis)
{
	const double	t[2] = {cos(theta), sin(theta)};
	t_mat4			rot;

	if (axis == 0)
		rot = (t_mat4){{{1, 0, 0, 0}, {0, t[0], t[1], 0}, \
						{0, -t[1], t[0], 0}, {0, 0, 0, 1}}};
	else if (axis == 1)
		rot = (t_mat4){{{t[0], 0, t[1], 0}, {0, 1, 0, 0}, \
						{-t[1], 0, t[0], 0}, {0, 0, 0, 1}}};
	else
		rot = (t_mat4){{{t[0], -t[1], 0, 0}, {t[1], t[0], 0, 0}, \
						{0, 0, 1, 0}, {0, 0, 0, 1}}};
	obj->orientation = mat4_mul(&rot, &obj->orientation);
}
