/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keycode.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:42:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/13 20:51:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEYCODE_H
# define MLX_KEYCODE_H

enum e_keycode
{
	A=0,
	S=1,
	D=2,
	F=3,
	H=4,
	G=5,
	Z=6,
	X=7,
	C=8,
	V=9,
	Q=12,
	W=13,
	E=14,
	R=15,
	Y=16,
	T=17,
	N1=18,
	N2=19,
	N3=20,
	N4=21,
	N6=22,
	N5=23,
	ESC=53,
};

enum e_mousecode
{
	LEFT_CLICK=1,
	RIGHT_CLICK=2,
	MIDDLE_CLICK=3,
	SCROLL_UP=4,
	SCROLL_DOWN=5
};

#endif