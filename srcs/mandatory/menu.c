/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:48:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/28 22:20:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

int	get_current_color(int x, int y, t_img *img)
{
	char	*addr;

	addr = img->addr + (y * img->line_len + x * img->bytes_per_pixel);
	return (*(unsigned int *)addr);
}

void	show_manual(t_dev *dev)
{
	char	*str[13];
	int		i;
	int		y;

	str[0] = "==============  manual  ==============";
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
		mlx_string_put(dev->mlx, dev->win, 12, y += 30, WHITE, str[i]);
}

void	put_manual_to_image(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = -1;
	while (++y < M_H)
	{
		x = -1;
		while (++x < M_W)
		{
			color = get_current_color(x, y, &data->img);
			mlx_pixel_put_image(\
			&data->img, x, y, alpha_blending(color, BLACK, ALPHA));
		}
	}
}

void	draw_menu_lines(t_img *img, int option)
{
	int	i;

	if (option == 1)
		return ;
	i = -1;
	while (++i < 3)
	{
		mlx_draw_line(\
		&(t_point){M_W + i, 0, WHITE}, &(t_point){M_W + i, I_H, WHITE}, img);
		mlx_draw_line(\
		&(t_point){i, 0, WHITE}, &(t_point){i, I_H, WHITE}, img);
		mlx_draw_line(\
		&(t_point){0, i, WHITE}, &(t_point){M_W, i, WHITE}, img);
		mlx_draw_line(\
		&(t_point){0, I_H - i - 1, WHITE}, &(t_point){M_W, I_H - i - 1, WHITE}, \
		img);
	}
}

// void	show_position(t_object *obj, t_camera *cam)
// {
// 	const char	*consts = {"   x: ", "   y: ", "   z: "};
// 	char		*str[8];
// 	int			i;

// 	str[0] = ft_itoa(obj->pos.v[0]);
// 	str[1] = ft_strjoin("   x : ", str[0]);
// 	str[2] = ft_itoa(obj->pos.v[1]);
// 	str[3] = ft_strjoin("   y : ", str[2]);
// 	str[4] = ft_itoa(obj->pos.v[2]);
// 	str[5] = ft_strjoin("   z : ", str[4]);
// 	str[6] = ft_strjoin(str[1], str[2]);
// 	str[7] = ft_strjoin(str[3], str[4]);
// 	mlx_string_put(dev->mlx, dev->win, 12, 80, WHITE, str[7]);
// 	i = -1;
// 	while (++i < 8)
// 		free(str[i]);
// }

// void	show_object_status(t_object *obj, t_dev *dev)
// {
// 	char	*str[8];
// 	int		i;

// 	str[0] = "==============  object  ==============";
// 	mlx_string_put(dev->mlx, dev->win, 12, 20, WHITE, str[0]);
// 	str[0] = "  position |";
// 	mlx_string_put(dev->mlx, dev->win, 12, 50, WHITE, str[0]);
// 	str[1] = 
// }

// void	show_camera_status(t_camera *cam, t_dev *dev)
// {
// }

// void	show_status(t_data *data)
// {
// 	char	*str;

// 	str = "==============  status  ==============";
// 	mlx_string_put(data->dev.mlx, data->dev.win, 12, 20, WHITE, str);
// 	show_object_status(&data->obj, &data->dev);
// 	show_camera_status(&data->cam, &data->dev);
// }
