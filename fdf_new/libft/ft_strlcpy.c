/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:22:38 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:32:03 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j])
		j++;
	if (dstsize == 0)
		return (j);
	while ((i < dstsize -1) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*
int main()
{
    int num1;
	int num2;
    char dst1[20] = "hello";
	char dst2[20] = "hello";
    char src[20] = "world";

	num1 = ft_strlcpy(dst1, src, 0);
    printf("%s\n", dst1);
	printf("%d\n", num1);
	num2 = strlcpy(dst2, src, 0);
    printf("%s\n", dst2);
	printf("%d\n", num2);

	return (0);
}
*/
