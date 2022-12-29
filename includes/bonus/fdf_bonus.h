/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 20:57:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:51:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

/*-------------- STANDARD HEADERS ---------------*/
# include <fcntl.h>

/*-------------- USER DEFINED HEADERS ------------*/
# include "matrix_bonus.h"
# include "get_next_line.h"
# include "libft.h"

/*----------- DEFINE MACRO CONSTANTS ------------*/
# define W_W 1920
# define W_H 1080
# define I_W 1920
# define I_H 1080
# define M_W 400
# define M_H 1080
# define TITLE "mlx"
# define CLEN 50
# ifndef FT_INT_MAX
#  define FT_INT_MAX 2147483647
# endif
# ifndef FT_INT_MIN
#  define FT_INT_MIN -2147483648
# endif
# define FT_PI27 0.11635528346628863846
# define ALPHA 500
# define RATIO 0.87

/*------------- STRUCT DECLARATIONS --------------*/

typedef enum e_change
{
	CAM_CHANGE = 0,
	OBJ_CHANGE = 1
}	t_change;

typedef enum e_hook_option
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELEASE = 5,
	MOTION_NOTIFY = 6,
	DESTROY_NOTIFY = 17,
}	t_hook_option;

typedef struct s_ctrl
{
	int	motion_flag;
}	t_ctrl;

// a node of linked list. each node stores a line of given map
typedef struct s_split_node
{
	char				**val;
	int					cnt;
	struct s_split_node	*nxt;
}	t_split_node;

// mlx
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
	char	*buff;
	int		bits_per_pixel;
	int		bytes_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
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
	double	scale[4];
	double	t_scale[4];
	t_vec4	pos;
	t_vec4	t_pos;
	t_mat4	orientation;
}	t_object;

typedef struct s_camera
{
	t_vec4	pos;
	t_vec4	t_pos;
	t_vec4	look_at;
	t_vec4	dir;
	t_vec4	up;
	t_vec4	side;
}	t_camera;

typedef struct s_data
{
	t_dev		dev;
	t_img		img;
	t_ctrl		ctrl;
	int			w;
	int			h;
	int			max;
	int			min;
	t_vec4		**vertex;
	int			**color;
	t_point		**screen;
	t_point		axis[6][2];
	t_object	obj;
	t_camera	cam;
	t_mat4		m_world;
	t_mat4		m_view;
	t_mat4		m_viewport;
	t_mat4		m_show;
	t_mat4		m;
}	t_data;

/*-------------- FUNCTION PROTOTYPES -------------*/
// process input
void	process_input(int argc, char **argv, t_data *data);
void	fdf_split_map_line(t_split_node *node, char const *s, char c);

// initialize
void	initialize_setting(t_data *data);
void	init_object(t_object *obj, t_data *data);

// camera view
void	init_camera_to_isometric_view(t_camera *cam, int opt);
void	init_camera_to_top_view(t_camera *cam, int opt);

// menu
void	show_manual(t_dev *dev);

// mlx_utils
void	mlx_pixel_put_buffer(t_img *img, int x, int y, int color);
int		mlx_render_next_frame(t_data *data);
int		terminate_program(t_data *data);

// mlx_key_press_hooks
int		key_press_hooks(int key, t_data *data);
int		key_release_hooks(int key, t_data *data);

// mlx_mouse_hooks
int		mouse_hooks(int mouse, int x, int y, t_data *data);
int		motion_hooks(int x, int y, t_data *data);

// mlx_draw
void	draw_line(const t_point *p, const t_point *q, t_img *img);
void	draw_object(t_point **scr, t_img *img, int h, int w);
void	draw_axis(t_point axis[6][2], t_img *img);

// color
void	set_vertex_color(t_vec4 **p, t_data *s);
int		get_color(const t_point *p, const t_point *q, int x);
int		alpha_blending(int color1, int color2, int alpha);

// transform
void	camera_get_view_vectors(t_camera *cam);
void	transform_world(t_object *obj, int h, int w, t_mat4 *m_world);
void	transform_view(t_camera *cam, t_mat4 *view_mat);
void	transform_viewport(t_mat4 *viewport_mat);
void	transform(t_data *s, int opt);
void	transform_vertex(t_data *data, t_vec4 **vtx, t_point **scr, t_mat4 *m);
void	transform_axis(t_point axis[6][2], t_mat4 *m);

// rotate
void	rotate(t_object *obj, double theta, int axis);

// show menu
void	show_manual(t_dev *dev);
void	put_manual_to_image(t_data *data);
void	draw_menu_lines(t_img *img, int option);

#endif