/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:49:33 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:27:25 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((32 <= c) && (c <= 126))
		return (1);
	return (0);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = isprint(32);
	result2 = ft_isprint(32);
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
