/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/29 23:12:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "key_mouse_code.h"

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_W || y >= I_H)
		return ;
	dst = img->addr + (y * img->line_len + x * img->bytes_per_pixel);
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_data *dat)
{
	t_vec4	tem_v[2];
	int		flag;
	int		i;

	i = -1;
	flag = 0;
	while (++i < 4)
	{
		if (dat->obj.t_scale[i] != dat->obj.scale[i])
		{
			dat->obj.t_scale[i] = \
			RATIO * dat->obj.t_scale[i] + (1 - RATIO) * dat->obj.scale[i];
			flag = 1;
		}
	}
	if (!vec4_equals(&dat->obj.t_pos, &dat->obj.pos))
	{
		tem_v[0] = vec4_scalar_mul(RATIO, &dat->obj.t_pos);
		tem_v[1] = vec4_scalar_mul(1 - RATIO, &dat->obj.pos);
		dat->obj.t_pos = vec4_add(&tem_v[0], &tem_v[1]);
		flag = 1;
	}
	if (flag == 1)
		transform(dat, OBJ_CHANGE);
	flag = 0;
	if (!vec4_equals(&dat->cam.t_pos, &dat->cam.pos))
	{
		tem_v[0] = vec4_scalar_mul(RATIO, &dat->cam.t_pos);
		tem_v[1] = vec4_scalar_mul(1 - RATIO, &dat->cam.pos);
		dat->cam.t_pos = vec4_add(&tem_v[0], &tem_v[1]);
		flag = 1;
	}
	if (flag == 1)
		transform(dat, CAM_CHANGE);
	ft_memset(dat->img.addr, 1, I_H * I_W * dat->img.bytes_per_pixel);
	transform_vertex(dat, dat->vertex, dat->screen, &dat->m);
	transform_axis(dat->axis, &dat->m_show);
	draw_object(dat->screen, &dat->img, dat->h, dat->w);
	draw_axis(dat->axis, &dat->img);
	put_manual_to_image(dat);
	draw_menu_lines(&dat->img, 0);
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
