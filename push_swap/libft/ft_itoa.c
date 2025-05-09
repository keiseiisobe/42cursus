/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:29:03 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/15 15:10:06 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_of_digit(long n)
{
	int	count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

static char	*when_minus(int *n_digit, int *c, long *__n)
{
	int		i;
	char	*str;

	*__n *= -1;
	*n_digit = num_of_digit(*__n);
	i = *n_digit;
	str = (char *)malloc((*n_digit + 1) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (1 <= i)
	{
		*c = *__n % 10;
		str[i] = *c + '0';
		*__n = *__n / 10;
		i--;
	}
	str[i] = '-';
	str[*n_digit + 1] = '\0';
	return (str);
}

static char	*when_plus(int *n_digit, int *c, long *__n)
{
	int		i;
	char	*str;

	*n_digit = num_of_digit(*__n);
	i = *n_digit - 1;
	str = (char *)malloc((*n_digit * sizeof(char) + 1));
	if (str == NULL)
		return (NULL);
	while (0 <= i)
	{
		*c = *__n % 10;
		str[i] = *c + '0';
		*__n = *__n / 10;
		i--;
	}
	str[*n_digit] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		n_digit;
	int		c;
	char	*str;
	long	__n;

	__n = n;
	if (__n < 0)
	{
		str = when_minus(&n_digit, &c, &__n);
		return (str);
	}
	else
	{
		str = when_plus(&n_digit, &c, &__n);
		return (str);
	}
}
/*
int main()
{
	char *str;

	str = ft_itoa(12340);
	printf("%s\n", str);
	free(str);
}
*/
