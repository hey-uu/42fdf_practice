/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:35 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/29 21:50:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	init_device_and_image(t_dev *dev, t_img *img)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, W_W, W_H, TITLE);
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, I_W, I_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
	img->bytes_per_pixel = img->bits_per_pixel / 8;
}

void	init_screen(t_data *data)
{
	int	i;

	data->screen = ft_malloc(sizeof(t_point *) * data->h);
	i = -1;
	while (++i < data->h)
	{
		data->screen[i] = ft_malloc(sizeof(t_point) * data->w);
	}
}

void	init_object(t_object *obj, t_data *data)
{
	double	scale[2];
	int		i;

	if (data->h == 0 || data->w == 0)
		return ;
	scale[0] = (double)I_H / (data->h * 2.5);
	scale[1] = (double)I_W / (data->w * 2.5);
	obj->t_scale[0] = scale[0];
	if (scale[1] < obj->t_scale[0])
		obj->t_scale[0] = scale[1];
	obj->scale[0] = obj->t_scale[0];
	i = 0;
	while (++i <= 3)
	{
		obj->t_scale[i] = 1;
		obj->scale[i] = 1;
	}
	obj->t_pos = (t_vec4){{0, 0, 0, 1}};
	obj->pos = (t_vec4){{0, 0, 0, 1}};
	obj->orientation = \
	(t_mat4){{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
}

void	init_transformation(t_data *s)
{	
	init_object(&s->obj, s);
	init_camera_to_isometric_view(&s->cam, 0);
	camera_get_view_vectors(&s->cam);
	transform_world(&s->obj, s->h - 1, s->w - 1, &s->m_world);
	transform_view(&s->cam, &s->m_view);
	transform_viewport(&s->m_viewport);
	s->m_show = mat4_mul(&s->m_viewport, &s->m_view);
	s->m = mat4_mul(&s->m_show, &s->m_world);
}

void	initialize_setting(t_data *data)
{
	data->ctrl = (t_ctrl){0};
	set_vertex_color(data->vertex, data);
	init_device_and_image(&data->dev, &data->img);
	init_screen(data);
	init_transformation(data);
}
