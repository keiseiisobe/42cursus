/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:23:14 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 16:22:39 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

# define WIN_HEIGHT 1500
# define WIN_WIDTH 1500
# define IMG_HEIGHT 1500
# define IMG_WIDTH 1500
# define MID_COLOR 0x0000FF00
# define MAX_COLOR 0x00FFFFFF
# define MIN_COLOR 0x00FFFFFF
# define SCALING 2
# define SCALING_HEIGHT 0.08
# define MOVE_X 250
# define MOVE_Y 300
# define X 1
# define Y 2
# define BEGIN 0
# define PARALLEL 1
# define VERTICAL 2

# define ESC_KEY 53

# define R 0
# define G 1
# define B 2

typedef struct s_map {
	char	**line;
	size_t	width;
	size_t	height;
	int		**matrix;
	size_t	x;
	size_t	y;
	int		ultimate_z;
}	t_map;

typedef struct s_fdf {
	void	*mlx;
	void	*window;
	void	*img;
	int		window_width;
	int		window_height;
}	t_fdf;

typedef struct s_img {
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_pos {
	int	begin_x;
	int	begin_y;
	int	begin_z;
	int	end_x;
	int	end_y;
	int	end_z;
	int	shift_x;
}	t_pos;

typedef struct s_pixel {
	double	delta_x;
	double	delta_y;
	double	pixels;
	double	pixel_x;
	double	pixel_y;
}	t_pixel;

typedef struct s_color {
	int	color;
	int	end_color;
	int	delta_color;
}	t_color;

int		**read_map(char *file_name, t_map *map);
void	put_deformed_num(t_pos *pos, t_map *map, int flag);
void	draw_map(t_map *map);
int		get_ultimate_z(t_map *map);
int		get_color(int Z, t_map *map);
int		get_delta_color(t_color *color, t_pos *pos, double pixels);
int		deal_key(int keycode, t_fdf *fdf);
int		close_window(t_fdf *fdf);
void	handle_error(bool is_error);

#endif
