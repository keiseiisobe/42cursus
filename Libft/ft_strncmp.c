/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:02:20 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:20:53 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (s1_cpy[i] && i < n - 1 && s1_cpy[i] == s2_cpy[i])
		i++;
	return (s1_cpy[i] - s2_cpy[i]);
}
/*
int main()
{
	char str1[10] = "abcdef";
	char str2[10] = "abcd";
	int result1;
	int result2;

	result1 = strncmp(str1, str2, 3);
	result2 = ft_strncmp(str1, str2, 3);
	printf("%d\n", result1);
	printf("%d\n", result2);
}
*/
