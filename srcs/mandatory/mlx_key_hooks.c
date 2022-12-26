/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:44:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/27 01:51:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keycode.h"

void	key_hook_object(int idx, t_data *data)
{
	static double	consts[15] = {0, 0.9, 1.1, -10, 10, -10, 10, -10, 10, \
					-FT_PI27, FT_PI27, -FT_PI27, FT_PI27, -FT_PI27, FT_PI27};

	if (idx == 0)
		init_object(&data->obj, data->h, data->w);
	else if (idx <= 2)
		data->obj.scale *= consts[idx];
	else if (idx <= 8)
		data->obj.pos.v[(idx - 3) / 2] += consts[idx];
	else if (idx <= 14)
		rotate(&data->obj, consts[idx], (idx - 9) / 2);
	transform(data, OBJ_CHANGE);
}

void	key_hook_camera(int idx, t_data *data)
{
	static double	consts[14] = {0, 0, 0, 0, 0, 0, 0, 0, \
								-5, 5, -5, 5, -5, 5};
	if (idx <= 7)
		init_camera_to_isometric_view(&data->cam, idx);
	else if (idx <= 13)
		data->cam.pos.v[(idx - 8) / 2] += consts[idx];
	else if (idx == 14)
		data->cam.look_at = (t_vec4){{0, 0, 0, 1}};
	else
		data->cam.look_at = data->obj.pos;
	transform(data, CAM_CHANGE);
	
}

int key_hooks(int key, t_data *data)
{
	static int	keys[32] = {K_ESC, K_BACK, K_MINUS, K_PLUS, \
						K_Q, K_W, K_E, K_R, K_T, K_Y, \
						K_A, K_S, K_D, K_F, K_G, K_H, \
						K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, \
						K_Z, K_X, K_C, K_V, K_B, K_N, \
						K_O, K_P};
	int			i;

	i = -1;
	while (++i < 32)
		if (keys[i] == key)
			break;
	if (i == 0)
		exit(0);
	else if (i <= 15)
		key_hook_object(i - 1, data);
	else if (i <= 31)
		key_hook_camera(i - 16, data);
	return (1);
}
