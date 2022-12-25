/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:59:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/25 16:12:41 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_test.h"
#include "mlx.h"
#include "keycode.h"

int	key_hook(int key, t_data *data)
{
	if (key == K_ESC)
	{
		mlx_destroy_image(data->dev.mlx, data->img.img);
		mlx_destroy_window(data->dev.mlx, data->dev.win);
		exit(0);
	}
	return (1);
}

int	render_next_frame(t_data *data)
{
	ft_memset(data->img.addr, 0, I_HEIGHT * I_WIDTH * data->img.bits_per_pixel / 8);
	project_to_image(&data->view.scr, &data->img);
	mlx_put_image_to_window(data->dev.mlx, data->dev.win, data->img.img, M_WIDTH, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	process_input(argc, argv, &data.map);
	init_dev(&data.dev);
	show_menu(&data.dev);
	show_projected_image(&data);
	mlx_loop_hook(data.dev.mlx, render_next_frame, &data);
	mlx_key_hook(data.dev.win, key_hook, &data);
	mlx_loop(data.dev.mlx);
	return (0);
}
 