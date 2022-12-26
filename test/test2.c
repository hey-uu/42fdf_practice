/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:21:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/22 19:36:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_pts
{
	int a;
	int	b;
}	t_pts;

int	round_to_int(double x)
{
	int	res;

	res = (int)(x * 10) % 10;
	if (res >= 5)
		return ((int)(x + 1));
	return ((int)x);
}

int main(void)
{
	t_pts	p = {1, 2};
	t_pts	q = {3, 4};

	q = p;
	printf("%d %d\n", q.a, q.b);

	double x = 3134324.6;
	double y = 323413.5;
	double z = 3423.2;

	printf("%d %d %d\n", round_to_int(x), round_to_int(y), round_to_int(z));
}