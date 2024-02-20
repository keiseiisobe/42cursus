/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:49:54 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:15:03 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	s_len;

	if (!s)
		return ;
	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		f(i, s);
		i++;
		s++;
	}
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

void ft_test(unsigned int i, char *s)
{
	*s += i;
}

int main()
{
	char s[] = "0000000000";

	ft_striteri(s, ft_test);
	printf("%s\n", s);
}
*/
