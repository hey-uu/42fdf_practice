/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 12:27:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "color.h"

void	show_menu(t_dev *dev)
{
	// static t_img	menu;
	// int				i;
	// int				j;

	// init_image(dev, &menu, M_WIDTH, M_HEIGHT);
	// i = -1;
	// while (++i < M_HEIGHT)
	// {
	// 	j = -1;
	// 	while (++j < M_WIDTH)
	// 		mlx_pixel_put_image(&menu, j, i, 0x8fC6D6F7);
	// }
	// mlx_put_image_to_window(dev->mlx, dev->win, menu.img, 0, 0);
	mlx_string_put(dev->mlx, dev->win, 10, 10, 0xffffff, "==menu==");
}
