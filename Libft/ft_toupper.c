/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:59 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:34:50 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (('a' <= c) && (c <= 'z'))
		c = c - 32;
	return (c);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = toupper('a');
	result2 = ft_toupper('a');
	printf("%c\n", result1);
	printf("%c\n", result2);
}
*/
