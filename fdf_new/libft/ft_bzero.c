/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:48:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:11:47 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*s_cpy;
	size_t	i;

	s_cpy = (char *)s;
	i = 0;
	while (i < n)
	{
		s_cpy[i] = '\0';
		i++;
	}
}
/*
int main()
{
	char str1[20] = "abcdefg";
	char str2[20] = "abcdefg";

	bzero(str1, 1);
	ft_bzero(str2, 1);
	printf("%c\n", str1[1]);
	printf("%c\n", str2[1]);
}
*/
