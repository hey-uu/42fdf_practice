/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:47:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/16 22:10:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	*ft_malloc(char *error_message, size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
	{
		if (error_message)
			write(2, error_message, ft_strlen(error_message));
		else
			write(2, "failed malloc", 13);
		exit(1);
	}
	return (new);
}
