/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:04:30 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/30 07:12:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	store_data_into_map(t_data *data, t_split_node *list)
{
	t_split_node	*tmp;
	int				x;
	int				i;
	int				j;

	data->vertex = ft_malloc(sizeof(t_vec4 *) * data->h);
	i = data->h;
	while (--i >= 0)
	{
		data->vertex[i] = ft_malloc(sizeof(t_vec4) * data->w);
		j = 0;
		while (j < data->w && j < list->cnt)
		{
			x = ft_atoi(list->val[j]);
			data->max = (x > data->max) * x + (x <= data->max) * data->max;
			data->min = (x < data->min) * x + (x >= data->min) * data->min;
			data->vertex[i][j] = (t_vec4){{j, i, x, 1}};
			free(list->val[j++]);
		}
		tmp = list;
		list = list->nxt;
		free(tmp->val);
		free(tmp);
	}
}

t_split_node	*fdf_make_new_node(char *line)
{
	t_split_node	*new;

	new = ft_malloc(sizeof(t_split_node));
	fdf_split_map_line(new, line, ' ');
	new->nxt = NULL;
	return (new);
}

void	fdf_add_node_front(t_split_node **head, t_split_node *new)
{
	if (!*head)
		*head = new;
	else
	{
		new->nxt = *head;
		*head = new;
	}
}

void	parse_map(t_data *data, int fd)
{
	char				*line;
	static t_split_node	*split_list;
	t_split_node		*new;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		new = fdf_make_new_node(line);
		free(line);
		fdf_add_node_front(&split_list, new);
		if (new->cnt > data->w)
			data->w = new->cnt;
		data->h++;
	}
	store_data_into_map(data, split_list);
}

void	process_input(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		ft_exit("invalid arguments\n", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit("failed to open map file\n", 1);
	data->min = FT_INT_MAX;
	data->max = FT_INT_MIN;
	parse_map(data, fd);
	close(fd);
}
