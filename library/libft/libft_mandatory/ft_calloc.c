/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 11:25:02 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*new;
	size_t			total;
	size_t			i;

	if (count > 0 && size > FT_SIZE_MAX / count)
		ft_exit(NULL, BADALLOC);
	total = count * size;
	new = ft_malloc(total);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return ((void *) new);
}
