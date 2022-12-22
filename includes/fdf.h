/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:57:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 23:35:45 by hyeyukim         ###   ########.fr       */
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
# include "vector.h"
# include "matrix.h"

/*----------- DEFINE MACRO CONSTANTS ------------*/
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define I_WIDTH 1620
# define I_HEIGHT 1080
# define M_WIDTH 300
# define M_HEIGHT 1080
# define INTVL 30
# define TITLE "mlx"
# define CAMDIST 100
# define SCALE 20

/*---------------------- TEMP ---------------------*/
# define PRINT_VIEW \
	printf("x : %d, y : %d, z : %d\n", \
	(int)obj->pos[j][i].v[0], \
	(int)obj->pos[j][i].v[1], \
	(int)obj->pos[j][i].v[2]);

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

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_two_points
{
	const t_point	*p;
	const t_point	*q;
	int				dx;
	int				dy;
	int				abs_dx;
	int				abs_dy;
}	t_two_points;

typedef struct s_object
{
	t_vec4	**pos;
	t_vec3	ori;
	int		h;
	int		w;
}	t_object;

typedef struct s_camera
{
	t_vec4	pos;
	t_vec3	ori;
	double	dist;
}	t_camera;

typedef struct s_world
{
	t_object	obj;
	t_camera	*cam;
}	t_world;

typedef struct s_screen
{
	t_point	**p;
	int		w;
	int		h;
}	t_screen;

typedef struct s_view
{
	t_object	obj;
	t_camera	*cam;
	t_screen	scr;
}	t_view;

typedef struct s_data
{
	t_map	map;
	t_dev	dev;
	t_img	img;
	t_world	world;
	t_view	view;
}	t_data;

/*-------------- FUNCTION PROTOTYPES -------------*/
// parsing
void	fdf_split_map_line(t_split_node *node, char const *s, char c);
void	process_input(int argc, char **argv, t_map *map);

// show images
void	show_menu(t_dev *dev);
void	show_projected_image(t_data *data);

// mlx utils
void	init_dev(t_dev *dev);
void	init_image(t_dev *dev, t_img *img, int w, int h);
void	mlx_pixel_put_image(t_img *img, int x, int y, int color);
int		update_frames(t_img *img);

// draw line
void	mlx_draw_line(const t_point *p, const t_point *q, t_img *img);

// object
void	init_object(int w, int h, t_object *obj, t_map *map);
void	transform_object(\
		const t_mat4 *m, t_object *obj, t_object *dst, t_vec3 ori);

// init transformations
void	init_transform_into_world(t_world *world, t_map *map);
void	init_transform_view(t_world *world, t_view *view);

// projection
void	project_to_image(t_screen *scr, t_img *img);

#endif