/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_something2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:13:55 by kisobe            #+#    #+#             */
/*   Updated: 2024/04/23 18:01:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_address(uintptr_t n, int *p)
{
	char			base[16];
	char			c;
	char			*base_str;
	unsigned int	i;

	base_str = "0123456789abcdef";
	i = 0;
	while (base_str[i])
	{
		base[i] = base_str[i];
		i++;
	}
	if (16 <= n)
	{
		ft_put_address(n / 16, p);
	}
	c = base[n % 16];
	if (*p == -1 || write(1, &c, 1) < 0)
	{
		*p = -1;
		return (-1);
	}
	(*p)++;
	return (*p);
}

int	ft_put_hexadec_low(unsigned int n, int *p)
{
	char			base[16];
	char			c;
	char			*base_str;
	unsigned int	i;

	base_str = "0123456789abcdef";
	i = 0;
	while (base_str[i])
	{
		base[i] = base_str[i];
		i++;
	}
	if (16 <= n)
	{
		ft_put_hexadec_low(n / 16, p);
	}
	c = base[n % 16];
	if (*p == -1 || write(1, &c, 1) < 0)
	{
		*p = -1;
		return (-1);
	}
	(*p)++;
	return (*p);
}

int	ft_put_hexadec_up(unsigned int n, int *p)
{
	char			base[16];
	char			c;
	char			*base_str;
	unsigned int	i;

	base_str = "0123456789ABCDEF";
	i = 0;
	while (base_str[i])
	{
		base[i] = base_str[i];
		i++;
	}
	if (16 <= n)
	{
		ft_put_hexadec_up(n / 16, p);
	}
	c = base[n % 16];
	if (*p == -1 || write(1, &c, 1) < 0)
	{
		*p = -1;
		return (-1);
	}
	(*p)++;
	return (*p);
}
