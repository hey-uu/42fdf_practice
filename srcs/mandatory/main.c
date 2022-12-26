/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:59:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 23:35:06 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int exit_program(t_data *data)
{
    mlx_destroy_image(data->dev.mlx, data->img.img);
    mlx_destroy_window(data->dev.mlx, data->dev.win);
    exit(0);
    return (1);
}

int	main(int argc, char **argv)
{
	static t_data	data;

	process_input(argc, argv, &data);
	set_vertex_color(data.vertex, &data);
	initialize_setting(&data);
	show_menu(&data.dev);
    mlx_hook(data.dev.win, 2, (1L<<0), key_hooks, &data);
	mlx_loop_hook(data.dev.mlx, render_next_frame, &data);
	mlx_loop(data.dev.mlx);
	return (0);
}
 