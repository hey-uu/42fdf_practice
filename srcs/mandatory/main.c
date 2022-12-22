/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:59:16 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 20:27:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_test.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	static t_data	data;

	process_input(argc, argv, &data.map);
	init_dev(&data.dev);
	show_menu(&data.dev);
	show_projected_image(&data);
	// mlx_loop_hook(dev.mlx, update_frames, &img);
	mlx_loop(data.dev.mlx);
	return (0);
}
 