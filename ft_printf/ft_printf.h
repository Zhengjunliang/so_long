/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:30:02 by juzheng           #+#    #+#             */
/*   Updated: 2022/11/27 16:30:03 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_put_char(int c);
int	ft_put_string(char *str);
int	ft_put_ptr(uintptr_t n);
int	ft_digits(int n);
int	ft_put_unsigned(unsigned int n);
int	ft_digits_hexa(unsigned int n, char format);
int	ft_printf(const char *str, ...);

#endif
