/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:30:55 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:32:33 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		s_len;
	char	*s2;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	s2 = (char *)malloc(s_len * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
char ft_test(unsigned int n, char c)
{
	char d;

	d = c + n;
	return (d);
}

int main()
{
	char *str = "ABCDEF";
	char *str2;
	
	str2 = ft_strmapi(str, ft_test);
	printf("%s\n", str2);
}
*/
