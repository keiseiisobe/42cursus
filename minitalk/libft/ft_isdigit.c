/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:24:06 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:27:17 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (('0' <= c) && (c <= '9'))
		return (1);
	return (0);
}
/*
int main()
{
	int result1;
	int result2;

	result1 = isdigit('4');
	result2 = ft_isdigit('4');
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
