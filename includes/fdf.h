/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:57:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 14:22:20 by hyeyun           ###   ########.fr       */
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
# define CD 10
# define SCALE 5
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648


/*------------- STRUCT DECLARATIONS --------------*/

// a node of linked list. each node stores a line of given map
typedef struct s_split_node
{
	char				**val;
	int					count;
	struct s_split_node	*next;
}	t_split_node;

// parsed map
typedef struct s_map
{
	t_vec4	**vertex;
	int		width;
	int		height;
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
	int color;
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
	double	scale;
	t_vec4	position;
	t_mat4	orientation;
}	t_object;

typedef struct s_camera
{
	t_vec4	position;
	t_vec4	look_at;
	t_vec4	dir;
	t_vec4	up;
	t_vec4	side;
}	t_camera;

typedef struct s_project
{
	int	a;
	int	r;
	int	l;
	int	t;
	int	b;
}	t_project;

typedef struct s_data
{
	int			w;
	int			h;
	int         max;
	int         min;
	t_vec4		**vertex;
	int         **color;
    t_point     **screen;
	t_dev		dev;
	t_img		img;
	t_object	obj;
	t_camera	cam;
	// t_project	proj;
	t_mat4		m_world;
	t_mat4		m_view;
	t_mat4		m_proj;
	t_mat4		m_viewport;
	t_mat4		m_show;
	t_mat4		m;
}	t_data;


/*-------------- FUNCTION PROTOTYPES -------------*/
// main
void	process_input(int argc, char **argv, t_data *data);
void	fdf_split_map_line(t_split_node *node, char const *s, char c);
void	initialize_setting(t_data *data);
void	show_menu(t_dev *dev);

// mlx_utils
void	mlx_pixel_put_image(t_img *img, int x, int y, int color);
int		key_hooks(int key, t_data *data);
int		render_next_frame(t_data *data);

// mlx_draw
void	mlx_draw_line(const t_point *p, const t_point *q, t_img *img);
void    mlx_draw_object_on_image(t_point **scr, t_img *img, int h, int w);
void    mlx_draw_axis_on_image(t_img *img);


// color
int     get_color(const t_point *p, const t_point *q, int x);
void	set_vertex_color(t_vec4 **p, t_data *s);

// transform
void	camera_get_view_vectors(t_camera *cam);
void	camera_set_isometric_view(t_camera *cam, int opt);
void	transform_world(t_object *obj, int h, int w, t_mat4 *m_world);
void	transform_view(t_camera *cam, t_mat4 *view_mat);
// void	project_orthographic(t_mat4 *proj_mat);
void	transform_viewport(t_mat4 *viewport_mat);
void    transform_vertex(t_data *data, t_vec4 **vertex, t_point **screen, t_mat4 *m);

#endif