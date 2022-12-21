/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:57:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 20:47:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*-------------- STANDARD HEADERS ---------------*/
# include <fcntl.h>
# include <stdio.h>

/*-------------- USER DEFINED HEADERS ------------*/
# include "get_next_line.h"
# include "libft.h"

/*----------- DEFINE MACRO CONSTANTS ------------*/
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define I_WIDTH 1420
# define I_HEIGHT 1080
# define M_WIDTH 500
# define M_HEIGHT 1080
# define INTVL 30
# define TITLE "mlx"

/*------------- STRUCT DECLARATIONS --------------*/

// a node of linked list. each node stores a line of given map
typedef struct s_split_node
{
	char				**data;
	int					count;
	struct s_split_node	*next;
}	t_split_node;

// parsed map
typedef struct s_map
{
	int		**pos;
	int		w;
	int		h;
}	t_map;

typedef struct s_dev
{
	void	*mlx;
	void	*win;
}	t_dev;

// data set for an image
typedef struct s_img
{
	t_dev	*dev;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

/*-------------- FUNCTION PROTOTYPES -------------*/
void	fdf_split_map_line(t_split_node *node, char const *s, char c);
void	process_input(int argc, char **argv, t_map *map);
void	show_menu(void);
void	show_projection_image(t_dev *dev, t_map *map, t_img *img);

#endif