/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:10:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 15:51:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	show_map(t_map *map)
{
	for (int i = 0 ; i < map->h ; i++)
	{
		for (int j = 0 ; j < map->w ; j++)
		{
			if (map->pos[i][j] != 0)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
