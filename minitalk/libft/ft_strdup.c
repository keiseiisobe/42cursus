/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:03:04 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 07:30:47 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		str_len;
	char	*p;
	int		i;

	str_len = ft_strlen(s1);
	p = (char *)malloc(str_len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int main()
{
	char *str1 = "hello";
	char *str2;
	char *str3;

	str2 = strdup(str1);
	str3 = ft_strdup(str1);

	if (str2 == NULL)
		printf("str2 fault\n");
	if (str3 == NULL)
		printf("str3 fault\n");
	printf("%s\n", str2);
	printf("%s\n", str3);
	free(str2);
	free(str3);
}
*/
