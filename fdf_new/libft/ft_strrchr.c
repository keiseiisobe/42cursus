/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:42:22 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:33:21 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		str_len;
	char	*str_finded;
	char	c_conv;

	c_conv = c;
	i = 0;
	str_len = ft_strlen(s);
	while (0 <= str_len)
	{
		if (s[str_len] == c_conv)
		{
			str_finded = (char *)&s[str_len];
			return (str_finded);
		}
		str_len--;
	}
	return (NULL);
}
/*
int main()
{
	char str[20] = "abcddefg";
	char *p1;
	char *p2;

	p1 = strrchr(str, 'a');
	p2 = ft_strrchr(str, 'a');

	printf("%s\n", p1);
	printf("%s\n", p2);
}
*/
