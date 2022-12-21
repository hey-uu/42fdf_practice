/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:04:30 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/20 15:51:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	store_data_into_map(t_map *map, t_split_node *list)
{
	int				i;
	int				j;
	t_split_node	*tmp;

	map->pos = ft_malloc(NULL, sizeof(int *) * map->h);
	i = map->h - 1;
	while (i >= 0)
	{
		map->pos[i] = ft_calloc(map->w, sizeof(int));
		j = 0;
		while (j < map->w && j < list->count)
		{
			map->pos[i][j] = ft_atoi(list->data[j]);
			free(list->data[j]);
			j++;
		}
		i--;
		tmp = list;
		list = list->next;
		free(tmp->data);
		free(tmp);
	}
}

t_split_node	*fdf_make_new_node(char *line)
{
	t_split_node	*new;

	new = ft_malloc(NULL, sizeof(t_split_node));
	fdf_split_map_line(new, line, ' ');
	new->next = NULL;
	return (new);
}

void	fdf_add_node_front(t_split_node **head, t_split_node *new)
{
	if (!*head)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	parse_map(t_map *map, int fd)
{
	char				*line;
	static t_split_node	*split_list;
	t_split_node		*new;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new = fdf_make_new_node(line);
		free(line);
		fdf_add_node_front(&split_list, new);
		if (new->count > map->w)
			map->w = new->count;
		map->h++;
	}
	store_data_into_map(map, split_list);
}

void	process_input(int argc, char **argv, t_map *map)
{
	int	fd;

	if (argc != 2)
		ft_exit("invalid arguments\n", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("failed to open map file\n", 1);
	parse_map(map, fd);
	// show_map(map);
	close(fd);
}
