/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:15:28 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:12:27 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s_cpy;
	char	c_edited;
	size_t	i;
	char	*p;

	s_cpy = (char *)s;
	c_edited = c;
	i = 0;
	while (i < n)
	{
		if (s_cpy[i] == c_edited)
		{
			p = &s_cpy[i];
			return (p);
		}
		i++;
	}
	return (NULL);
}	
/*
int main()
{
	char str[20] = "abcdefg";
	char *p1;
	char *p2;

	p1 = memchr(str, 'c', 3);
	p2 = ft_memchr(str, 'c', 3);
	printf("%s\n", p1);
	printf("%s\n", p2);
}
*/
