/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/28 22:09:52 by hyeyukim         ###   ########.fr       */
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
