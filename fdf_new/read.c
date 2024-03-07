/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:44:54 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 10:16:31 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	get_height(char *file_name)
{
	int		fd;
	size_t	i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	handle_error(fd < 0);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

size_t	get_width(char *file_name)
{
	int		fd;
	char	**line;
	size_t	i;
	char	*line_tmp;

	fd = open(file_name, O_RDONLY);
	handle_error(fd < 0);
	line_tmp = get_next_line(fd);
	line = ft_split(line_tmp, ' ');
	free(line_tmp);
	handle_error(line == NULL);
	i = 0;
	while (line[i] && line[i][0] != '\n')
		free(line[i++]);
	free(line[i]);
	free(line);
	while (1)
	{
		line_tmp = get_next_line(fd);
		if (line_tmp == NULL)
			break ;
		free(line_tmp);
	}
	close(fd);
	return (i);
}

void	put_num_into_matrix(t_map *map, size_t *i)
{
	size_t	j;

	map->matrix[*i] = (int *)malloc(map->width * sizeof(int));
	handle_error(map->matrix[*i] == NULL);
	j = 0;
	while (j < map->width)
	{
		map->matrix[*i][j] = ft_atoi(map->line[j]);
		j++;
	}
	(*i)++;
	j = 0;
	while (map->line[j])
		free(map->line[j++]);
	free(map->line);
}

int	**read_map(char *file_name, t_map *map)
{
	int		fd;
	size_t	i;
	char	*line_tmp;

	map->width = get_width(file_name);
	map->height = get_height(file_name);
	fd = open(file_name, O_RDONLY);
	handle_error(fd < 0);
	map->matrix = (int **)malloc(map->height * sizeof(int *));
	handle_error(map->matrix == NULL);
	i = 0;
	while (i < map->height)
	{
		line_tmp = get_next_line(fd);
		map->line = ft_split(line_tmp, ' ');
		free(line_tmp);
		handle_error(map->line == NULL);
		put_num_into_matrix(map, &i);
	}
	close(fd);
	return (map->matrix);
}
