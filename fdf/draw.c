/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:54:42 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 10:52:57 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	initialize_for_drawing(t_pixel *pixel, t_color *color, t_pos *pos,
		t_map *map)
{
	pixel->delta_x = pos->end_x - pos->begin_x;
	pixel->delta_y = pos->end_y - pos->begin_y;
	pixel->pixels = sqrt(pixel->delta_x * pixel->delta_x + pixel->delta_y
			* pixel->delta_y);
	pixel->delta_x /= pixel->pixels;
	pixel->delta_y /= pixel->pixels;
	pixel->pixel_x = pos->begin_x;
	pixel->pixel_y = pos->begin_y;
	color->color = get_color(pos->begin_z, map);
	color->end_color = get_color(pos->end_z, map);
	color->delta_color = get_delta_color(color, pos, pixel->pixels);
}

void	draw_line(t_img *img, t_pos *pos, t_map *map)
{
	t_pixel	*pixel;
	t_color	*color;
	int		i;

	pixel = malloc(sizeof(t_pixel));
	color = malloc(sizeof(t_color));
	initialize_for_drawing(pixel, color, pos, map);
	i = 0;
	while (i <= pixel->pixels)
	{
		if ((pixel->pixel_x >= 0 && pixel->pixel_x < IMG_WIDTH)
			&& (pixel->pixel_y >= 0 && pixel->pixel_y < IMG_HEIGHT))
		{
			my_mlx_pixel_put(img, pixel->pixel_x, pixel->pixel_y, color->color);
			if (pos->begin_z > pos->end_z)
				color->color -= color->delta_color;
			else if (pos->begin_z < pos->end_z)
				color->color += color->delta_color;
		}
		pixel->pixel_x += pixel->delta_x;
		pixel->pixel_y += pixel->delta_y;
		i++;
	}
	free(pixel);
	free(color);
}

void	loop_to_draw_line(t_map *map, t_pos *pos, t_img *img)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			put_deformed_num(pos, map, BEGIN);
			if (map->x < map->width - 1)
			{
				put_deformed_num(pos, map, PARALLEL);
				draw_line(img, pos, map);
			}
			if (map->y < map->height - 1)
			{
				put_deformed_num(pos, map, VERTICAL);
				draw_line(img, pos, map);
			}
			map->x++;
		}
		map->y++;
	}
}

void	draw_map(t_map *map)
{
	t_fdf	*fdf;
	t_img	*img;
	t_pos	*pos;

	fdf = malloc(sizeof(t_fdf));
	img = malloc(sizeof(t_img));
	pos = malloc(sizeof(t_pos));
	fdf->mlx = mlx_init();
	fdf->window_width = WIN_HEIGHT;
	fdf->window_height = WIN_WIDTH;
	fdf->window = mlx_new_window(fdf->mlx, fdf->window_width,
			fdf->window_height, "Hello World");
	fdf->img = mlx_new_image(fdf->mlx, IMG_WIDTH, IMG_HEIGHT);
	img->addr = mlx_get_data_addr(fdf->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	map->ultimate_z = get_ultimate_z(map);
	loop_to_draw_line(map, pos, img);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->img, 0, 0);
	mlx_hook(fdf->window, 2, 1L << 0, deal_key, fdf);
	mlx_hook(fdf->window, 17, 1L << 17, close_window, fdf);
	mlx_loop(fdf->mlx);
}
