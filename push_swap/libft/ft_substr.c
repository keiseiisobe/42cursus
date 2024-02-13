/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:23:12 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:23:26 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_input_str(size_t len, unsigned int start, char const *s)
{
	size_t	s_len;
	size_t	i;
	char	*s_copy;

	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	if (s_len < start)
		len = 0;
	s_copy = malloc(len * sizeof(char) + 1);
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while ((i < len) && (s[i]))
	{
		s_copy[i] = s[i + start];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;

	if (s == NULL)
		return (NULL);
	if (len == 0)
	{
		s_copy = malloc(1);
		if (s_copy == NULL)
			return (NULL);
		s_copy[0] = '\0';
		return (s_copy);
	}
	if ((SIZE_MAX - 1) / len < sizeof(char))
		return (NULL);
	s_copy = ft_input_str(len, start, s);
	return (s_copy);
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
	char *str1 = "tripouille";
	char *str2;

	str2 = ft_substr(str1, 0, 10);
	printf("%s\n", str2);
	free(str2);
}
*/
