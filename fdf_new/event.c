/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:51:33 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/12 10:23:40 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int keycode, t_fdf *fdf)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		exit(0);
	}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
}
