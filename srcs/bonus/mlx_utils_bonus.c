/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:54:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:54:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "mlx.h"
#include "key_mouse_code_bonus.h"

void	mlx_pixel_put_buffer(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_W || y >= I_H)
		return ;
	dst = img->buff + (y * img->line_len + x * img->bytes_per_pixel);
	*(unsigned int *)dst = color;
}

void	interpolate_cam_values(t_data *data)
{
	t_vec4	tem_v[2];
	int		flag;

	flag = 0;
	if (!vec4_equals(&data->cam.t_pos, &data->cam.pos))
	{
		tem_v[0] = vec4_scalar_mul(RATIO, &data->cam.t_pos);
		tem_v[1] = vec4_scalar_mul(1 - RATIO, &data->cam.pos);
		data->cam.t_pos = vec4_add(&tem_v[0], &tem_v[1]);
		flag = 1;
	}
	if (flag == 1)
		transform(data, CAM_CHANGE);
}

void	interpolate_obj_values(t_data *data)
{
	t_vec4	tem_v[2];
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	while (++i < 4)
	{
		if (data->obj.t_scale[i] != data->obj.scale[i])
		{
			data->obj.t_scale[i] = \
			RATIO * data->obj.t_scale[i] + (1 - RATIO) * data->obj.scale[i];
			flag = 1;
		}
	}
	if (!vec4_equals(&data->obj.t_pos, &data->obj.pos))
	{
		tem_v[0] = vec4_scalar_mul(RATIO, &data->obj.t_pos);
		tem_v[1] = vec4_scalar_mul(1 - RATIO, &data->obj.pos);
		data->obj.t_pos = vec4_add(&tem_v[0], &tem_v[1]);
		flag = 1;
	}
	if (flag == 1)
		transform(data, OBJ_CHANGE);
}

int	mlx_render_next_frame(t_data *dat)
{
	interpolate_obj_values(dat);
	interpolate_cam_values(dat);
	ft_memset(dat->img.buff, 0, I_H * I_W * dat->img.bytes_per_pixel);
	transform_vertex(dat, dat->vertex, dat->screen, &dat->m);
	transform_axis(dat->axis, &dat->m_show);
	draw_object(dat->screen, &dat->img, dat->h, dat->w);
	draw_axis(dat->axis, &dat->img);
	put_manual_to_image(dat);
	draw_menu_lines(&dat->img, 0);
	ft_memcpy(dat->img.addr, dat->img.buff, \
			I_W * I_H * dat->img.bytes_per_pixel);
	mlx_put_image_to_window(dat->dev.mlx, dat->dev.win, dat->img.img, 0, 0);
	show_manual(&dat->dev);
	return (0);
}

int	terminate_program(t_data *data)
{
	mlx_destroy_image(data->dev.mlx, data->img.img);
	mlx_destroy_window(data->dev.mlx, data->dev.win);
	exit(0);
}
