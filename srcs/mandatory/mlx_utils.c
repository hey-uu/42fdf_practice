/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:21:49 by hyeyun            #+#    #+#             */
/*   Updated: 2022/12/27 01:54:22 by hyeyukim         ###   ########.fr       */
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

int	render_next_frame(t_data *dat)
{
	ft_memset(dat->img.addr, 0, I_H * I_W * dat->img.bytes_per_pixel);
	transform_vertex(dat, dat->vertex, dat->screen, &dat->m);
	transform_axis(dat->axis, &dat->m_show);
	mlx_draw_object(dat->screen, &dat->img, dat->h, dat->w);
	mlx_draw_axis(dat->axis, &dat->img);
	mlx_put_image_to_window(dat->dev.mlx, dat->dev.win, dat->img.img, M_W, 0);
	return (0);
}

void	show_menu(t_dev *dev)
{
	char	*str[13];
	int		i;
	int		y;
	
	str[0] = "====menu====";
	str[1] = "axis : x(red), y(green), z(blue)";
	str[2] = "object scaling: +(up) -(down)";
	str[3] = "object translation: ";
	str[4] = "Q(-x) W(+x) E(-y) R(+y) T(-z) Y(+z)";
	str[5] = "object rotation(local coordinate) : ";
	str[6] = "A(+x) S(-x) D(-y) F(+y) G(-z) H(+z)";
	str[7] = "object initilize position: backspace";
	str[8] = "camera translation: ";
	str[9] = "Z(-x) X(+x) C(-y) V(+y) B(-z) N(+z)";
	str[10] = "camera looks at origin : O";
	str[11] = "camera looks at object : P";
	str[12] = "isometric view(eight direction) : 1~8";
	y = 20;
	i = -1;
	while (++i < 13)
		mlx_string_put(dev->mlx, dev->win, 10, y += 30, YELLOW, str[i]);
}
