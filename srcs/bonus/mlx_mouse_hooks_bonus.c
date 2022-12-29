/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_hooks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:27:09 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:12:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "key_mouse_code_bonus.h"

int	mouse_hooks(int mouse, int x, int y, t_data *data)
{
	x = 0;
	y = 0;
	if (mouse == M_SCROLL_UP)
	{
		data->obj.scale[0] *= 1.1;
		if (data->obj.scale[0] > 1000)
			data->obj.scale[0] = 1000;
	}
	else if (mouse == M_SCROLL_DOWN)
	{
		data->obj.scale[0] *= 0.9;
		if (data->obj.scale[0] < 0.01)
			data->obj.scale[0] = 0.01;
	}
	else if (mouse == M_LEFT_CLICK)
	{
		data->ctrl.motion_flag = (data->ctrl.motion_flag == 0);
	}
	transform(data, OBJ_CHANGE);
	return (1);
}

int	motion_hooks(int x, int y, t_data *data)
{
	static int	prev[2];

	if (data->ctrl.motion_flag == 0)
	{
		prev[0] = 0;
		prev[1] = 0;
		return (1);
	}
	if (!prev[0] && !prev[1])
	{
		prev[0] = x;
		prev[1] = y;
		return (1);
	}
	data->obj.pos.v[0] += x - prev[0];
	data->obj.pos.v[1] += prev[1] - y;
	prev[0] = x;
	prev[1] = y;
	transform(data, OBJ_CHANGE);
	return (1);
}
