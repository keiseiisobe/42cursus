/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 06:44:24 by kisobe            #+#    #+#             */
/*   Updated: 2024/01/19 11:24:14 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*input;

	if ((size == 0) || (count == 0))
	{
		input = malloc(0);
		if (input == NULL)
			return (NULL);
		ft_memset(input, '\0', 0);
	}
	else
	{
		if (SIZE_MAX / size < count)
			return (NULL);
		input = malloc(count * size);
		if (input == NULL)
			return (NULL);
		ft_memset(input, '\0', count * size);
	}
	return (input);
}

/*
void *ft_memset(void *b, int c, size_t len)
{
	char *d_cpy = (char *)b;
	char c_cpy = c;
	size_t i;

	i = 0;
	while(i < len)
	{
		d_cpy[i] = c_cpy;
		i++;
	}
	return (b);
}

int main()
{
	char *ch1;
	char *ch2;

	ch1 = (char *)calloc(0, 0);
	if (ch1 == NULL)
		printf("ch1 fault");
	printf("%s\n", ch1);
	free(ch1);

	ch2 = (char *)ft_calloc(INT_MIN, INT_MIN);
	if (ch2 == NULL)
		printf("ch2 fault");
	else
	{
		printf("%s\n", ch2);
		free(ch2);
	}
}
*/
