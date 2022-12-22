/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_split_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:20:56 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 00:09:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	get_wordcount(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == '\0' || s[i + 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

static size_t	ft_getlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	fill_split(char **res, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	res_idx;

	res_idx = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_getlen(&s[i], c);
			res[res_idx] = ft_malloc(NULL, len + 1);
			ft_strlcpy(res[res_idx], &s[i], len + 1);
			i += (len - 1);
			res_idx++;
		}
		i++;
	}
	res[res_idx] = NULL;
}

void	fdf_split_map_line(t_split_node *node, char const *s, char c)
{
	size_t	word_count;
	char	**res;

	if (!s)
		return ;
	word_count = get_wordcount(s, c);
	res = ft_malloc(NULL, sizeof(char *) * (word_count + 1));
	fill_split(res, s, c);
	node->data = res;
	node->count = word_count;
}
