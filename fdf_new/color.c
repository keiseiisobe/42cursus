/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:48:21 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 10:53:54 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgb(int color, int flag)
{
	if (flag == R)
		return ((color >> 16) & 0xFF);
	else if (flag == G)
		return ((color >> 8) & 0xFF);
	else
		return (color & 0xFF);
}

int	create_color(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_ultimate_z(t_map *map)
{
	size_t	i;
	size_t	j;
	int		max;

	max = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (fabs((double)map->matrix[i][j]) > max)
				max = fabs((double)map->matrix[i][j]);
			j++;
		}
		i++;
	}
	return (max);
}

int	get_color(int Z, t_map *map)
{
	int	dif_color;

	if (Z == 0)
		return (MID_COLOR);
	else
	{
		dif_color = MAX_COLOR - MID_COLOR;
		return (MID_COLOR + dif_color * (Z / map->ultimate_z));
	}
}

int	get_delta_color(t_color *color, t_pos *pos, double pixels)
{
	int	r;
	int	g;
	int	b;

	if (pos->begin_z == pos->end_z)
		return (0);
	else if (pos->begin_z > pos->end_z)
	{
		r = get_rgb(color->color, R) - get_rgb(color->end_color, R);
		g = get_rgb(color->color, G) - get_rgb(color->end_color, G);
		b = get_rgb(color->color, B) - get_rgb(color->end_color, B);
		return (create_color(r / pixels, g / pixels, b / pixels));
	}
	else
	{
		r = get_rgb(color->end_color, R) - get_rgb(color->color, R);
		g = get_rgb(color->end_color, G) - get_rgb(color->color, G);
		b = get_rgb(color->end_color, B) - get_rgb(color->color, B);
		return (create_color(r / pixels, g / pixels, b / pixels));
	}
}
