/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:30:54 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/01 14:48:36 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_if_minus(int *i_p, const char *str)
{
	int	if_minus;

	if_minus = 1;
	if ((str[*i_p] == '-') || (str[*i_p] == '+'))
	{
		if (('0' <= str[*i_p + 1]) && (str[*i_p + 1] <= '9'))
		{
			if (str[*i_p] == '-')
				if_minus = -1;
			(*i_p)++;
		}
	}
	return (if_minus);
}

static int	change_to_int(int i, const char *str, int result)
{
	int	int_num;

	while (('0' <= str[i]) && (str[i] <= '9'))
	{
		int_num = str[i] - 48;
		result = result * 10;
		result = result + int_num;
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	if_minus;
	int	result;

	i = 0;
	while (str[i])
	{
		result = 0;
		if_minus = ft_if_minus(&i, str);
		if (('0' <= str[i]) && (str[i] <= '9'))
		{
			result = change_to_int(i, str, result);
			return (result * if_minus);
		}
		else if ((9 <= str[i]) && (str[i] <= 13))
			i++;
		else if (32 == str[i])
			i++;
		else
			return (0);
	}
	return (0);
}
/*
#include <stdio.h>
int main()
{
	char str[20] = "-134\n";
	int result1;
	int result2;

	result1 = atoi(str);
	result2 = ft_atoi(str);
	printf("%d", result1);
	printf("%d", result2);
}
*/
