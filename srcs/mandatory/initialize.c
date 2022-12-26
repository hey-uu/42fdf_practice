/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:35 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 21:52:48 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define I_MAT (t_mat4){{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}

void	init_device_and_image(t_dev *dev, t_img *img)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, W_W, W_H, TITLE);
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, I_W, I_H);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
}

void	init_screen(t_data *data)
{
	int i;

	data->screen = ft_malloc(sizeof(t_point *) * data->h);
	i = -1;
	while (++i < data->h)
	{
		data->screen[i] = ft_malloc(sizeof(t_point) * data->w);        
	}
}

void	init_object(t_object *obj, int map_h, int map_w)
{
	double	scale1;
	double	scale2;

	scale1 = (I_H) / (map_h * 2);
	scale2 = (I_W) / (map_w * 2);
	obj->scale = scale1;
	if (scale2 < scale1)
		obj->scale = scale2;
	obj->pos = (t_vec4){{0, 0, 0, 1}};
	obj->orientation = I_MAT;
}

void	init_transformation(t_data *s)
{	
	init_object(&s->obj, s->h, s->w);
	init_camera_to_isometric_view(&s->cam, 0);
	transform_world(&s->obj, s->h, s->w, &s->m_world);
	transform_view(&s->cam, &s->m_view);
	transform_viewport(&s->m_viewport);
	s->m_show = mat4_mul(&s->m_viewport, &s->m_view);
	s->m = mat4_mul(&s->m_show, &s->m_world);
}

void	initialize_setting(t_data *data)
{
	init_device_and_image(&data->dev, &data->img);
	init_screen(data);
	init_transformation(data);
}