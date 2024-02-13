/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:07:38 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:18:47 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d_cpy;
	unsigned char	c_cpy;
	size_t			i;

	d_cpy = (unsigned char *)b;
	c_cpy = c;
	i = 0;
	while (i < len)
	{
		d_cpy[i] = c_cpy;
		i++;
	}
	return (b);
}	
/*
int main()
{
	char str1[20] = "abcdefg";
	char str2[20] = "abcdefg";

	memset(str1+7, '1', 3);
	ft_memset(str2+7, '1', 3);
	printf("%s\n", str1);
	printf("%s\n", str2);
}
*/
