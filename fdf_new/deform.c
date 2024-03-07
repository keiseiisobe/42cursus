/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deform.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:52:03 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 10:20:58 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	deform(double x, double y, double z, int flag)
{
	x *= SCALING;
	y *= SCALING;
	z *= SCALING_HEIGHT;
	if (flag == X)
	{
		x = x * cos(30 * M_PI / 180) - y * cos(30 * M_PI / 180);
		return (x + MOVE_X);
	}
	else
	{
		y = x * sin(30 * M_PI / 180) + y * sin(30 * M_PI / 180) - z;
		return (y + MOVE_Y);
	}
}

void	put_deformed_num(t_pos *pos, t_map *map, int flag)
{
	if (flag == BEGIN)
	{
		pos->begin_z = map->matrix[map->y][map->x];
		pos->begin_x = deform(map->x, map->y, pos->begin_z, X);
		pos->begin_y = deform(map->x, map->y, pos->begin_z, Y);
	}
	else if (flag == PARALLEL)
	{
		pos->end_z = map->matrix[map->y][map->x + 1];
		pos->end_x = deform(map->x + 1, map->y, pos->end_z, X);
		pos->end_y = deform(map->x + 1, map->y, pos->end_z, Y);
	}
	else if (flag == VERTICAL)
	{
		pos->end_z = map->matrix[map->y + 1][map->x];
		pos->end_x = deform(map->x, map->y + 1, pos->end_z, X);
		pos->end_y = deform(map->x, map->y + 1, pos->end_z, Y);
	}
}
