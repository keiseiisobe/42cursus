/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:54:54 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/07 07:23:02 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include "Libft/libft.h"
#include "GetNextLine/get_next_line.h"

#define BeginX_def 570
#define BeginY_def 150
#define RED 0x00FF0000
#define WHITE 0x00FFFFFF
#define BLUE 0x000000FF
#define HEIGHT_MULTIPLE 5

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

typedef struct {
	char	*line;
	char	**line_splited;
	int	row_len;
	int	pre_row_len;
	int	column_len;
	double	max_height;
	double	min_height;
} t_nums_info;

typedef struct {
	void	*mlx;
	void	*window;
	int		window_width;
	int		window_height;
} t_fdf;

typedef struct {
	double	beginX;
	double	beginY;
	double	beginZ;
	double	endX;
	double	endY;
	double	endZ;
	double	sliding_valueX;
	double	sliding_valueY;
	double	pixels;
	double	halfZ_percentage;
} t_position;

typedef struct {
	double	heighest_color;
	double	middle_color;
	double	lowest_color;
	double	color_dif;
	int	color_per_pixel_up;
	int	color_per_pixel_low;
	double	current_color;
	double	begin_color;
	double	end_color;
	int		r;
	int		g;
	int		b;
	int		r_dif;
	int		g_dif;
	int		b_dif;
} t_color;

int	create_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	get_max_height(int *nums, t_nums_info *nums_info)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (i < nums_info->row_len * (nums_info->column_len - 1))
	{
		if (nums[i] > height)
		{
			height = nums[i];
		}
		i++;
	}
	return (height);
}

int	get_min_height(int *nums, t_nums_info *nums_info)
{
	int	height;
	int	i;

	i = 0;
	height = nums[i];
	while (i < nums_info->row_len * (nums_info->column_len - 1))
	{
		if (nums[i] < height)
		{
			height = nums[i];
		}
		i++;
	}
	return (height);
}

int	get_color(int Z, t_color *color, int max_height)
{
	if (Z > 0)
	{
		color->r = get_r(color->heighest_color);
		color->g = get_g(color->heighest_color);
		color->b = get_b(color->heighest_color);
		color->color_dif = color->heighest_color - color->middle_color;
		if (color->color_dif > 0)
			return (create_color(color->r * (Z / max_height), color->g * (Z / max_height), color->b * (Z / max_height)));
		return (create_color(color->r * (Z / max_height), color->g * (Z / max_height), color->b * (Z / max_height)));
	}
	else if (Z < 0)
	{
		Z *= -1;
		color->r = get_r(color->lowest_color);
		color->g = get_g(color->lowest_color);
		color->b = get_b(color->lowest_color);
		color->color_dif = color->lowest_color - color->middle_color;
		if (color->color_dif > 0)
			return (create_color(color->r * (Z / max_height), color->g * (Z / max_height), color->b * (Z / max_height)));
		return (create_color(color->r * (Z / max_height), color->g * (Z / max_height), color->b * (Z / max_height)));
	}
	return (color->middle_color);
}

void	change_color(t_position *position, t_nums_info *nums_info, t_color *color, int upper_flag)
{
	if (position->beginZ == position->endZ)
		color->current_color = get_color(position->beginZ, color, nums_info->max_height);
	if ((position->beginZ > 0 && position->endZ < 0) || (position->beginZ < 0 && position->endZ > 0))
	{
		if (upper_flag == 1)
		{
			if (color->begin_color > color->middle_color)
			{
				color->current_color = create_color(color->r - (color->r_dif / (position->halfZ_percentage * position->pixels)), color->g - (color->g_dif /
							(position->halfZ_percentage * position->pixels)), color->b - (color->b_dif / (position->halfZ_percentage * position->pixels)));
			}
			else
			{
				color->current_color = create_color(color->r - (color->r_dif / (position->halfZ_percentage * position->pixels)), color->g - (color->g_dif /
							(position->halfZ_percentage * position->pixels)), color->b - (color->b_dif / (position->halfZ_percentage * position->pixels)));
			}
		}
		else if (upper_flag == 0)
		{
			if (color->end_color > color->middle_color)
			{
				color->current_color = create_color(color->r - (color->r_dif / ((1 - position->halfZ_percentage) * position->pixels)), color->g - (color->g_dif /
							((1 - position->halfZ_percentage) * position->pixels)), color->b - (color->b_dif / ((1 - position->halfZ_percentage) * position->pixels)));
			}
			else
			{
				color->current_color = create_color(color->r - (color->r_dif / ((1 - position->halfZ_percentage) * position->pixels)), color->g - (color->g_dif /
							((1 - position->halfZ_percentage) * position->pixels)), color->b - (color->b_dif / ((1 - position->halfZ_percentage) * position->pixels)));
			}
		}
	}
	else
	{
		color->current_color = create_color(color->r - (color->r_dif / (position->halfZ_percentage * position->pixels)), color->g - (color->g_dif /
					(position->halfZ_percentage * position->pixels)), color->b - (color->b_dif / (position->halfZ_percentage * position->pixels)));
	}
//	printf("end of function\n");
}

void	draw_line(t_fdf *fdf, t_position *position, t_nums_info *nums_info)
{
	double deltaX = position->endX - position->beginX;
	double deltaY = (position->endY - position->endZ) - (position->beginY - position->beginZ);
	double pixelX;
	double pixelY;
	int	i = 0;
	int	upper_flag = 1;
	position->halfZ_percentage = 1;
	t_color	*color;
	color = malloc(sizeof(t_color));
	color->heighest_color = RED;
	color->middle_color = WHITE;
	color->lowest_color = BLUE;

	position->pixels = sqrt(deltaX * deltaX + deltaY * deltaY);
	deltaX = deltaX / position->pixels;
	deltaY = deltaY / position->pixels;
	pixelX = position->beginX;
	pixelY = position->beginY - position->beginZ;

	color->begin_color = get_color(position->beginZ, color, nums_info->max_height);
	color->end_color = get_color(position->endZ, color, nums_info->max_height);
	if ((position->beginZ > 0 && position->endZ < 0) || (position->beginZ < 0 && position->endZ > 0))
	{
		position->halfZ_percentage = fabs(position->beginZ) / fabs(position->beginZ - position->endZ);
		color->r_dif = get_r(color->begin_color) - get_r(color->middle_color);
		color->g_dif = get_g(color->begin_color) - get_g(color->middle_color);
		color->b_dif = get_b(color->begin_color) - get_b(color->middle_color);
	}
	else
	{
		color->r_dif = get_r(color->begin_color) - get_r(color->end_color);
		color->g_dif = get_g(color->begin_color) - get_g(color->end_color);
		color->b_dif = get_b(color->begin_color) - get_b(color->end_color);
	}
	color->current_color = color->begin_color;
	while (i < position->halfZ_percentage * position->pixels)
	{
		mlx_pixel_put(fdf->mlx, fdf->window, pixelX, pixelY, color->current_color);
		pixelX = pixelX + deltaX;
		pixelY = pixelY + deltaY;
		color->r = get_r(color->current_color);
		color->g = get_g(color->current_color);
		color->b = get_b(color->current_color);
		change_color(position, nums_info, color, upper_flag);
		i++;
	}
	color->current_color = color->middle_color;
	color->r_dif = color->r - get_r(color->end_color);
	color->g_dif = color->g - get_g(color->end_color);
	color->b_dif = color->b - get_b(color->end_color);
	while (i < position->pixels)
	{
		upper_flag = 0;
		mlx_pixel_put(fdf->mlx, fdf->window, pixelX, pixelY, color->current_color);
		pixelX = pixelX + deltaX;
		pixelY = pixelY + deltaY;
		color->r = get_r(color->current_color);
		color->g = get_g(color->current_color);
		color->b = get_b(color->current_color);
		change_color(position, nums_info, color, upper_flag);
		i++;
	}
	free(color);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL && strs[i][0] != '\n')
		i++;
	return (i);
}

int	*ft_memoryjoin(int *nums, int row_len, int column_len)
{
	int	*num_joined;
	int	i;

	if (nums == NULL)
	{
		nums = malloc(row_len * sizeof(int));
		return (nums);
	}
	num_joined = malloc(row_len * column_len * sizeof(int));
	if (num_joined == NULL)
		return (NULL);
	i = 0;
	while (i < row_len * (column_len - 1))
	{
		num_joined[i] = nums[i];
		i++;
	}
	free(nums);
	nums = NULL;
	return (num_joined);
}

void	handle_different_row_len(t_nums_info *nums_info)
{
	if (nums_info->pre_row_len == -1)
	{
		nums_info->row_len = ft_strslen(nums_info->line_splited);
	}
	else if (nums_info->pre_row_len != ft_strslen(nums_info->line_splited))
	{
		if (ft_strslen(nums_info->line_splited) - nums_info->pre_row_len < 0)
			nums_info->row_len = nums_info->pre_row_len;
	}
	else
		nums_info->row_len = ft_strslen(nums_info->line_splited);
	nums_info->pre_row_len = nums_info->row_len;
}

int	*read_map(char *argv, t_nums_info *nums_info)
{
	int		fd;
	int	i;
	int	j;
	int		*nums = NULL;

	fd = open(argv, O_RDONLY);
	nums_info->column_len = 1;
	nums_info->pre_row_len = -1;
	i = 0;
	while (1)
	{
		nums_info->line = get_next_line(fd);
		if (nums_info->line == NULL)
			break ;
		nums_info->line_splited = ft_split(nums_info->line, ' ');
		free(nums_info->line);
		if (nums_info->line_splited == NULL)
			return (0);
		handle_different_row_len(nums_info);
		nums = ft_memoryjoin(nums, nums_info->row_len, nums_info->column_len);
		if (nums == NULL)
			return (0);
		j = 0;
		while (i < nums_info->row_len * nums_info->column_len)
			nums[i++] = ft_atoi(nums_info->line_splited[j++]);
		free(nums_info->line_splited);
		nums_info->column_len++;
	}
	nums_info->column_len--;
	return (nums);
}

void	draw_map(int *nums, t_nums_info *nums_info)
{
	t_fdf	*fdf;
	t_position	*position;
	int	i;

	fdf = malloc(sizeof(t_fdf));
	position = malloc(sizeof(t_position));
	fdf->window_width = 1150;
	fdf->window_height = 950;
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, fdf->window_width, fdf->window_height, "mlx_test");
	position->sliding_valueX = 500 * pow(nums_info->row_len, -1);
	position->sliding_valueY = 300 * pow(nums_info->column_len, -1);
	nums_info->max_height = get_max_height(nums, nums_info) * HEIGHT_MULTIPLE;
	nums_info->min_height = get_min_height(nums, nums_info) * HEIGHT_MULTIPLE;
	if (fabs(nums_info->max_height) < fabs(nums_info->min_height))
		nums_info->max_height = nums_info->min_height;
	i = 0;
	while (i < nums_info->row_len * nums_info->column_len)
	{
		if (i == 0)
		{
			if (nums_info->row_len >= nums_info->column_len)
			{
				position->beginX = BeginX_def - (nums_info->row_len / nums_info->column_len) * 150;
				position->beginY = BeginY_def - 100;
			}
			else if (nums_info->row_len < nums_info->column_len)
			{
				position->beginX = BeginX_def + (nums_info->column_len / nums_info->row_len) * 100;
				position->beginY = BeginY_def + 250;
			}
		}
		else if (i % nums_info->row_len == 0)
		{
			position->beginX = BeginX_def - (nums_info->row_len / nums_info->column_len) * 150 - position->sliding_valueX * (i / nums_info->row_len);
			position->beginY = BeginY_def - 100 + position->sliding_valueY * (i / nums_info->row_len);
		}
		else
		{
			position->beginX += position->sliding_valueX;
			position->beginY += position->sliding_valueY;
		}
		if ((i != nums_info->row_len - 1) && (i - nums_info->row_len + 1) % nums_info->row_len != 0) 
		{
			position->endX = position->beginX + position->sliding_valueX;
			position->endY = position->beginY + position->sliding_valueY;
			position->beginZ = nums[i] * HEIGHT_MULTIPLE;
			position->endZ = nums[i + 1] * HEIGHT_MULTIPLE;
			draw_line(fdf, position, nums_info);
		}
		if (i < nums_info->row_len * (nums_info->column_len - 1))
		{
			position->endX = position->beginX - position->sliding_valueX;
			position->endY = position->beginY + position->sliding_valueY;
			position->beginZ = nums[i] * HEIGHT_MULTIPLE;
			position->endZ = nums[i + nums_info->row_len] * HEIGHT_MULTIPLE;
			draw_line(fdf, position, nums_info);
		}
		i++;
	}
	mlx_loop(fdf->mlx);
	free(fdf);
	free(position);
}

int main(int argc, char*argv[])
{
	t_nums_info	*nums_info;
	int	*nums;

	if (argc != 2)
	{
		printf("Invalid argument !!!\n");
		return (0);
	}
	nums_info = malloc(sizeof(t_nums_info));
	if (nums_info == NULL)
		return (0);
	nums = read_map(argv[1], nums_info);
	draw_map(nums, nums_info);
	free(nums_info);
	free(nums);
}
