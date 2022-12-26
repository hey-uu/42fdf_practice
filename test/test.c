#include <stdio.h>
#include "matrix.h"

void	show_vec4(t_vec4 v)
{
	for (int i = 0 ; i < 4 ; i++)
		printf("%f ", v.v[i]);
	printf("\n");
}

void	show_mat4(t_mat4 m)
{
	for (int i = 0 ; i < 4 ; i++)
	{
		for (int j = 0 ; j < 4 ; j++)
			printf("%f ", m.m[i][j]);
		printf("\n");
	}
}

int main(void)
{
	t_mat4 m1 = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}};
	t_vec4 e[4] = {{{1, 0, 0, 0}}, {{0, 1, 0, 0}}, {{0, 0, 1, 0}}, {{0, 0, 0, 1}}};
	t_mat4	m2 = {{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};

	for (int i = 0 ; i < 4 ; i++)
		show_vec4((mat4_vec_mul(&m1, &e[i])));
	show_mat4((mat4_mul(&m1, &m2)));
}