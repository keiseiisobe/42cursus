/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisobe <kisobe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:13:51 by kisobe            #+#    #+#             */
/*   Updated: 2024/02/04 17:24:42 by kisobe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	if_char(va_list ap);
int	if_char_p(va_list ap);
int	if_void_p(va_list ap);
int	if_decimal(va_list ap);
int	if_unsigned_decimal(va_list ap);
int	if_hexadec_low(va_list ap);
int	if_hexadec_up(va_list ap);
int	ft_put_int(int n, int *p);
int	ft_put_unsigned_int(unsigned int n, int *p);
int	ft_put_address(uintptr_t n, int *p);
int	ft_put_hexadec_low(unsigned int n, int *p);
int	ft_put_hexadec_up(unsigned int n, int *p);

#endif
