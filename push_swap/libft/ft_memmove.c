/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:56:23 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:28:19 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;

	d_copy = (unsigned char *)dst;
	s_copy = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst <= src)
		ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		while (0 < len)
		{
			d_copy[len - 1] = s_copy[len - 1];
			len--;
		}
	}
	return (dst);
}
/*
int main()
{
	char dst1[0xF0];
	char dst2[0xF0];
	char src[30] = "this is a good nyancat !\r\n";

	memmove(dst1, src, 27);
	printf("%s\n", dst1);
	ft_memmove(dst2, src, 27);
	printf("%s\n", dst2);
}
*/
