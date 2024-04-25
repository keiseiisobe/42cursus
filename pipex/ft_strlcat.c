/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:00:54 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:19:54 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;

	if ((dst == NULL && dstsize == 0) || (dstsize <= ft_strlen(dst)))
		return (dstsize + ft_strlen(src));
	i = ft_strlen(dst);
	d_len = ft_strlen(dst);
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (d_len + ft_strlen(src));
}
/*
size_t	ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int main()
{
	char dst1[20] = "hello";
	char dst2[20] = "hello";
	char src[20] = "world";
	int return1;
	int return2;

	return1 = strlcat(dst1, src, 10);
	printf("%s\n", dst1);
	printf("%d\n", return1);
	return2 = ft_strlcat(dst2, src, 10);
	printf("%s\n", dst2);
	printf("%d\n", return2);
}
*/
