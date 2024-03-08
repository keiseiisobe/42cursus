/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:43:52 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:27:09 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((0 <= c) && (c <= 127))
		return (1);
	return (0);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = isascii(127);
	result2 = ft_isascii(127);
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
