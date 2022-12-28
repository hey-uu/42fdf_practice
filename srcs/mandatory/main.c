/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:59:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/28 12:37:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	process_input(argc, argv, &data);
	initialize_setting(&data);
	show_manual(&data.dev);
	mlx_hook(data.dev.win, KEY_PRESS, 0, key_hooks, &data);
	mlx_hook(data.dev.win, KEY_RELEASE, 0, key_release_hooks, &data);
	mlx_hook(data.dev.win, BUTTON_PRESS, 0, mouse_hooks, &data);
	mlx_hook(data.dev.win, MOTION_NOTIFY, 0, motion_hooks, &data);
	mlx_hook(data.dev.win, DESTROY_NOTIFY, 0, terminate_program, &data);
	mlx_loop_hook(data.dev.mlx, render_next_frame, &data);
	mlx_loop(data.dev.mlx);
	return (0);
}
 