/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:05:06 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/19 16:22:17 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_same(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*count_s2len(char const *s1, char const *set, char *s2, int start)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(s1);
	while ((ft_is_same(s1[i], set)) && s1[i])
		start = (i++) + 1;
	i = ft_strlen(s1) - 1;
	while ((ft_is_same(s1[i], set)) && (0 <= i))
		end = i--;
	if (end < start)
		return (ft_strdup("\0"));
	s2 = (char *)malloc((end - start) * sizeof(char) + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		s2[i] = s1[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		start;

	if (!s1 || !set)
		return (NULL);
	s2 = NULL;
	if (*set == '\0')
	{
		s2 = ft_strdup(s1);
		return (s2);
	}
	start = 0;
	s2 = count_s2len(s1, set, s2, start);
	return (s2);
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

char	*ft_strdup(const char *s1)
{
	int str_len;
	char *p;
	int i;

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

int main()
{
	char *str1 = "242";
	char set[5] = {'2', 'X'};
	char *str2;

	str2 = ft_strtrim(str1, set);
	printf("%s\n", str2);
	free(str2);
}
*/
