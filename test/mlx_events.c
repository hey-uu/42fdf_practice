/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:28:35 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/13 20:33:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define XSIZE 1920
#define YSIZE 1080
#define TITLE "hello"
#define BYTESIZE 8

enum e_key_code
{
	ESC=53
};

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	close_window(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, XSIZE, YSIZE, TITLE);
	mlx_hook(vars.win, 2, 1L << 0, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
