/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:26:09 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:20:27 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		str_len;
	char	*str_finded;
	char	c_conv;

	c_conv = c;
	i = 0;
	str_len = ft_strlen(s);
	while (i <= str_len)
	{
		if (s[i] == c_conv)
		{
			str_finded = (char *)&s[i];
			return (str_finded);
		}
		i++;
	}
	return (NULL);
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
	char str[30] = "abcdefghijklmabcdefghijklmn";
	char *p1;
	char *p2;

	p1 = strchr(str, 'n');
	p2 = ft_strchr(str, 'n');

	printf("%s\n", p1);
	printf("%s\n", p2);
}
*/
