/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 22:48:42 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "keycode.h"
#include "color.h"

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_W || y >= I_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hooks(int key, t_data *data)
{
	static int  num_key[8] = {K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8};
	int         i;

	if (key == K_ESC)
	{
		mlx_destroy_image(data->dev.mlx, data->img.img);
		mlx_destroy_window(data->dev.mlx, data->dev.win);
		exit(0);
	}
	i = -1;
	while (++i < 8)
	{
		if (key == num_key[i])
		{
			transform(data, i);
			return (1);
		}
	}
	if (key == K_MINUS || key == K_PLUS || key == K_A || key == K_S || \
		key == K_D || key == K_F || key == K_R || key == K_T || key == K_BACK || \
		key == K_Z || key == K_X || key == K_C || key == K_V || \
		key == K_B || key == K_N)
	{
		if (key == K_BACK)
			init_object(&data->obj, data->h, data->w);
		else if (key == K_MINUS)
			data->obj.scale *= 0.9;
		else if (key == K_PLUS)
			data->obj.scale *= 1.1;
		else if (key == K_A)
			data->obj.pos.v[0] -= 10;
		else if (key == K_S)
			data->obj.pos.v[0] += 10;
		else if (key == K_D)
			data->obj.pos.v[1] -= 10;
		else if (key == K_F)
			data->obj.pos.v[1] += 10;
		else if (key == K_R)
			data->obj.pos.v[2] -= 10;
		else if (key == K_T)
			data->obj.pos.v[2] += 10;
		else if (key == K_Z)
			rotate_local_coord(&data->obj, -M_2_PI / 6, 0);
		else if (key == K_X)
			rotate_local_coord(&data->obj, M_2_PI / 6, 0);
		else if (key == K_C)
			rotate_local_coord(&data->obj, -M_2_PI / 6, 1);
		else if (key == K_V)
			rotate_local_coord(&data->obj, M_2_PI / 6, 1);
		else if (key == K_B)
			rotate_local_coord(&data->obj, -M_2_PI / 6, 2);
		else if (key == K_N)
			rotate_local_coord(&data->obj, M_2_PI / 6, 2);
		transform(data, OBJ_CHANGE);
		return (1);
	}
	if (key == K_P || key == K_O || key == K_H || key == K_J \
		|| key == K_K || key == K_L || key == K_Y || key == K_U)
	{
		if (key == K_P)
			data->cam.look_at = data->obj.pos;
		else if (key == K_O)
			data->cam.look_at = (t_vec4){{0, 0, 0, 1}};
		else if (key == K_H)
			data->cam.pos.v[0] -= 10;
		else if (key == K_J)
			data->cam.pos.v[0] += 10;
		else if (key == K_K)
			data->cam.pos.v[1] -= 10;
		else if (key == K_L)
			data->cam.pos.v[1] += 10;
		else if (key == K_Y)
			data->cam.pos.v[2] -= 10;
		else if (key == K_U)
			data->cam.pos.v[2] += 10;
		transform(data, CAM_CHANGE);
	}
	return (1);
}

int	render_next_frame(t_data *data)
{
	ft_memset(data->img.addr, 0, I_H * I_W * data->img.bits_per_pixel / 8);
	transform_vertex(data, data->vertex, data->screen, &data->m);
	transform_axis(data->axis, &data->m_show);
	mlx_draw_object_on_image(data->screen, &data->img, data->h, data->w);
	mlx_draw_axis_on_image(data->axis, &data->img);
	mlx_put_image_to_window(data->dev.mlx, data->dev.win, data->img.img, M_W, 0);
	return (0);
}

void	show_menu(t_dev *dev)
{
	char	 	*str[13];
	int i;
	int y;
	
	str[0] = "====menu====";
	str[1] = "axis : x(red), y(green), z(blue)";
	str[2] = "object translation: ";
	str[3] = "A(-x) S(+x) D(-y) F(+y) R(-z) T(+z)";
	str[4] = "object scaling: +(up) -(down)";
	str[5] = "object rotation(local coordinate) : ";
	str[6] = "Z(+x) X(-x) C(-y) V(+y) B(-z) N(+z)";
	str[7] = "object init setting: backspace";
	str[8] = "camera translation:";
	str[9] = "H(-x) J(+x) K(-y) L(+y) Y(-z) U(+z)";
	str[10] = "camera looks at origin : O";
	str[11] = "camera looks at object : P";
	str[12] = "isometric view(eight direction) : 1~8";

	y = 20;
	i = -1;
	while (++i < 13)
	{
		mlx_string_put(dev->mlx, dev->win, 10, y, YELLOW, str[i]);
		y += 20;
	}
}
