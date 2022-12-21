/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:59:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 20:34:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_test.h"
#include "mlx.h"

void	init_dev(t_dev *dev)
{
	dev->mlx = mlx_init();
	dev->win = mlx_new_window(dev->mlx, W_WIDTH, W_HEIGHT, TITLE);
}

int	update_frames(t_img *img)
{
	ft_memset(img->addr, 0, I_WIDTH * I_HEIGHT * img->bits_per_pixel / 8);
	mlx_put_image_to_window(img->dev->mlx, img->dev->win, img->img, M_WIDTH, 0);
	return (1);
}

int	main(int argc, char **argv)
{
	static t_map	map;
	static t_dev	dev;
	static t_img	img;

	init_dev(&dev);
	process_input(argc, argv, &map);
	show_menu();
	show_projection_image(&dev, &map, &img);
	// mlx_loop_hook(dev.mlx, update_frames, &img);
	mlx_loop(dev.mlx);
	return (0);
}
