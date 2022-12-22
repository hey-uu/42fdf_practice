/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:17:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 22:00:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	project_to_image(t_screen *scr, t_img *img)
{
	int	i;
	int	j;

	i = -1;
	while (++i < scr->h)
	{
		j = -1;
		while (++j < scr->w)
		{
			if (i != scr->h - 1)
				mlx_draw_line(&scr->p[i][j], &scr->p[i + 1][j], img);
			if (j != scr->w - 1)
				mlx_draw_line(&scr->p[i][j], &scr->p[i][j + 1], img);
			// if (i != scr->h - 1 && j != scr->w - 1)
			// 	mlx_draw_line(&scr->p[i][j], &scr->p[i + 1][j + 1], img);
		}
	}
}

void	show_projected_image(t_data *data)
{
	init_image(&data->dev, &data->img, I_WIDTH, I_HEIGHT);
	init_transform_into_world(&data->world, &data->map);
	init_transform_view(&data->world, &data->view);
	project_to_image(&data->view.scr, &data->img);
	mlx_put_image_to_window(\
		data->dev.mlx, data->dev.win, data->img.img, M_WIDTH, 0);
}
