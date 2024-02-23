/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:52:11 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/19 16:21:13 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strscount(char const *s, char c)
{
	int	i;
	int	strs_count;

	i = 0;
	strs_count = 0;
	if (s[0] != c)
		strs_count++;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c))
		{
			if (s[i + 1] != '\0')
				strs_count++;
		}
		i++;
	}
	return (strs_count);
}

static int	ft_char_count(char const *s, int *i_p, char c)
{
	int		char_count;

	char_count = 0;
	while (s[*i_p] != c && s[*i_p])
	{
		(*i_p)++;
		char_count++;
	}
	return (char_count);
}

static char	**ft_loop_str(char const *s, char c, char **pp, int *strs_count)
{
	int	i;
	int	start;
	int	char_count;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			start = i;
			char_count = ft_char_count(s, &i, c);
			pp[*strs_count] = ft_substr(s, start, char_count);
			if (pp[*strs_count] == NULL)
			{
				while (0 <= *strs_count)
					free(pp[(*strs_count)--]);
				free(pp);
				return (NULL);
			}
			(*strs_count)++;
		}
	}
	return (pp);
}

char	**ft_split(char const *s, char c)
{
	int		strs_count;
	char	**pp;

	if (!s)
		return (NULL);
	pp = (char **)malloc(ft_strscount(s, c) * sizeof(char *) + 1);
	if (!pp)
		return (NULL);
	strs_count = 0;
	pp = ft_loop_str(s, c, pp, &strs_count);
	if (pp == NULL)
		return (NULL);
	pp[strs_count] = NULL;
	return (pp);
}

/*

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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *s_copy;
	size_t i;
	size_t s_len;

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
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	if (s_len < start)
		len = 0;
	s_copy = malloc((len + 1) * sizeof(char));
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
	char *str = "AB_DEUX_TROIS";
	char c = '_';
	char **pp;
	
	pp = ft_split(str, c);
	printf("%s\n", pp[0]);
	printf("%s\n", pp[1]);
	free(pp[0]);
	free(pp[1]);
	printf("%s\n", pp[2]);
	printf("%s\n", pp[3]);
	free(pp[2]);
	free(pp[3]);
	printf("%s\n", pp[4]);
	printf("%s\n", pp[5]);
	free(pp[4]);
	free(pp[5]);
}
*/
