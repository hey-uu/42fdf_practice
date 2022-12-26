/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/26 23:41:36 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

void	mlx_pixel_put_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= I_W || y >= I_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

