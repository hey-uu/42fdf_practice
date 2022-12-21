/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:10:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 19:06:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

/*-------------- USER DEFINED HEADERS ------------*/
# include "vector.h"

/*----------- DEFINE MACRO CONSTANTS ------------*/
# define CDIST 20

/*------------- STRUCT DECLARATIONS --------------*/
typedef struct s_object
{
	t_vec4	**pos;
	t_vec3	rot;
	int		h;
	int		w;
}	t_object;

typedef struct s_camera
{
	t_vec4	pos;
	t_vec3	rot;
	double	dist;
}	t_camera;

typedef struct s_world
{
	t_object	*obj;
	t_camera	*cam;
}	t_world;

typedef struct s_view
{
	t_object	*obj;
	t_camera	*cam;
}	t_view;


/*-------------- FUNCTION PROTOTYPES -------------*/
void	transform_into_world(t_world *world, t_map *map);
void	transform_view(t_world *world, t_view *view);
void	project_to_image(t_view *view, t_img *img);

#endif