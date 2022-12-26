/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:35 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 15:31:41 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

#define I_MAT (t_mat4){{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}}

void	init_device(t_dev *dev)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, W_WIDTH, W_HEIGHT, TITLE);
}

void	init_image(t_dev *dev, t_img *img, int w, int h)
{
	img->dev = dev;
	img->img = mlx_new_image(dev->mlx, w, h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
				&img->line_len, &img->endian);
}

void	init_object(t_object *obj, int map_h, int map_w)
{
	double	scale1;
	double	scale2;

	scale1 = (I_HEIGHT) / (map_h * 2);
	scale2 = (I_WIDTH) / (map_w * 2);
	obj->scale = scale1;
	if (scale2 < scale1)
		obj->scale = scale2;
	obj->position = (t_vec4){{0, 0, 0, 1}};
	obj->orientation = I_MAT;
}

void	init_transformation(t_data *s)
{	
	init_object(&s->obj, s->h, s->w);
	transform_world(&s->obj, s->h, s->w, &s->m_world);
	camera_set_isometric_view(&s->cam, 0);
	transform_view(&s->cam, &s->m_view);
	// project_orthographic(&s->m_proj);
	transform_viewport(&s->m_viewport);
	s->m_show = mat4_mul(&s->m_viewport, &s->m_view);
    printf("m_show\n");
    mat4_print(&s->m_show);
	//s->m_show = mat4_mul3(&s->m_viewport, &s->m_proj, &s->m_view);
	s->m = mat4_mul(&s->m_show, &s->m_world);
    printf("m_final\n");
    mat4_print(&s->m);
}

void    init_screen(t_data *data)
{
    int i;

    data->screen = ft_malloc(sizeof(t_point *) * data->h);
    i = -1;
    while (++i < data->h)
    {
        data->screen[i] = ft_malloc(sizeof(t_point) * data->w);        
    }
}

void	initialize_setting(t_data *data)
{
	init_device(&data->dev);
	init_image(&data->dev, &data->img, I_WIDTH, I_HEIGHT);
	init_transformation(data);
    init_screen(data);
}