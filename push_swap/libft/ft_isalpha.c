/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:03:34 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:26:57 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		return (1);
	else if (('a' <= c) && (c <= 'z'))
		return (1);
	return (0);
}
/*
int	main()
{
	int result1;
	int result2;

	result1 = isalpha(100);
	result2 = ft_isalpha(100);
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
