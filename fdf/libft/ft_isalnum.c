/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:32:06 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:26:49 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	else if (('A' <= c) && (c <= 'Z'))
		return (1);
	else if (('a' <= c) && (c <= 'z'))
		return (1);
	return (0);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = isalnum('A');
	result2 = ft_isalnum('A');
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
