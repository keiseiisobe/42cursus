/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:59:34 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:19:12 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d_cpy;
	unsigned char	*s_cpy;
	size_t			i;

	d_cpy = (unsigned char *)dst;
	s_cpy = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d_cpy[i] = s_cpy[i];
		i++;
	}
	return (dst);
}
/*
int main()
{
	char dst1[20] = "cdcd";
	char dst2[20] = "cdcd";
	char src[20] = "ab";

	memcpy(dst1, src, 2);
	ft_memcpy(dst2, src, 2);
	printf("%s\n", dst1);
	printf("%s\n", dst2);
}
*/
