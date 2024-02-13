/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:56:22 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:29:27 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	__n;

	__n = n;
	if (__n < 0)
	{
		__n = __n * -1;
		write(fd, "-", 1);
	}
	if (__n >= 10)
		ft_putnbr_fd(__n / 10, fd);
	c = (__n % 10) + '0';
	write(fd, &c, 1);
}
/*
int main()
{
	ft_putnbr_fd(-2147483648, 0);
}
*/
