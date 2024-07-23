/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:19:53 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:34:56 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		c = c + 32;
	return (c);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = tolower('A');
	result2 = ft_tolower('A');
	printf("%c\n", result1);
	printf("%c\n", result2);
}
*/
