/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:12:20 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 11:21:55 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	handle_error(argc != 2);
	handle_error(ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".fdf", 4));
	map = malloc(sizeof(t_map));
	handle_error(map == NULL);
	map->matrix = read_map(argv[1], map);
	handle_error(map->matrix == NULL);
	draw_map(map);
	return (0);
}
