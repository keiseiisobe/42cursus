/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:50:31 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:33:04 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count_to_reset;

	if (*needle == '\0')
		return ((char *)haystack);
	if ((haystack == NULL && len == 0) || *needle == '\0')
		return (NULL);
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		count_to_reset = 0;
		while (haystack[i] == needle[j] && i < len && haystack[i])
		{
			i++;
			j++;
			count_to_reset++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i - count_to_reset]);
		i = i - count_to_reset;
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char b_str[20] = "world";
	char s_str[20] = "world";
	char *p1;
	char *p2;

	p1 = strnstr(b_str, s_str, 10);
	printf("%s\n", p1);
	p2 = ft_strnstr(b_str, s_str, 10);
	printf("%s\n", p2);
}
*/
