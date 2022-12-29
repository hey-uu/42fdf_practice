/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_hooks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:53:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:53:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "key_mouse_code_bonus.h"

void	key_hook_object_scales(int idx, t_data *data)
{
	static double	consts[8] = {0.9, 1.1, 0.9, 1.1, 0.9, 1.1, 0.9, 1.1};

	data->obj.scale[idx / 2] *= consts[idx];
	if (data->obj.scale[idx / 2] < 0.01)
		data->obj.scale[idx / 2] = 0.01;
	else if (data->obj.scale[idx / 2] > 1000)
		data->obj.scale[idx / 2] = 1000;
}

void	key_hook_object(int idx, t_data *data)
{
	static double	consts[12] = {\
					-20, 20, -20, 20, -20, 20, \
					-FT_PI27, FT_PI27, -FT_PI27, FT_PI27, -FT_PI27, FT_PI27};

	if (idx == 0)
		init_object(&data->obj, data);
	else if (idx <= 8)
		key_hook_object_scales(idx - 1, data);
	else if (idx <= 14)
		data->obj.pos.v[(idx - 9) / 2] += consts[idx - 9];
	else if (idx <= 20)
		rotate(&data->obj, consts[idx - 9], (idx - 15) / 2);
	transform(data, OBJ_CHANGE);
}

void	key_hook_camera(int idx, t_data *data)
{
	static double	consts[6] = {-5, 5, -5, 5, -5, 5};

	if (idx == 0)
		init_camera_to_top_view(&data->cam, 0);
	else if (idx <= 8)
		init_camera_to_isometric_view(&data->cam, idx - 1);
	else if (idx <= 14)
		data->cam.pos.v[(idx - 9) / 2] += consts[idx - 9];
	else if (idx == 15)
		data->cam.look_at = (t_vec4){{0, 0, 0, 1}};
	else
		data->cam.look_at = data->obj.pos;
	transform(data, CAM_CHANGE);
}

int	key_press_hooks(int key, t_data *data)
{
	static int	keys[39] = {\
				K_ESC, K_BACK, K_MINUS, K_PLUS, \
				K_U, K_I, K_J, K_K, K_M, K_COMMA, \
				K_Q, K_W, K_E, K_R, K_T, K_Y, \
				K_A, K_S, K_D, K_F, K_G, K_H, \
				K_0, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, \
				K_Z, K_X, K_C, K_V, K_B, K_N, \
				K_O, K_P};
	int			i;

	i = -1;
	while (++i < 39)
		if (keys[i] == key)
			break ;
	if (i == 0)
		terminate_program(data);
	else if (i <= 21)
		key_hook_object(i - 1, data);
	else if (i <= 38)
		key_hook_camera(i - 22, data);
	return (1);
}

int	key_release_hooks(int key, t_data *data)
{
	static int	enter_cnt;

	if (key == K_ENTER)
	{
		enter_cnt = (enter_cnt + 1) % 9;
		if (enter_cnt <= 7)
			init_camera_to_isometric_view(&data->cam, enter_cnt);
		else
			init_camera_to_top_view(&data->cam, 0);
		transform(data, CAM_CHANGE);
	}
	if (key == K_CTRL)
	{
		data->ctrl.motion_flag++;
		if (data->ctrl.motion_flag >= 2)
			data->ctrl.motion_flag = 0;
	}
	return (1);
}
