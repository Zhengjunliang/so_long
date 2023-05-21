/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:36:14 by juzheng           #+#    #+#             */
/*   Updated: 2022/11/27 16:36:16 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_printf_arg(va_list ap, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_put_char(va_arg(ap, int));
	if (format == 's')
		len = ft_put_string(va_arg(ap, char *));
	if (format == 'p')
		len = ft_put_ptr(va_arg(ap, unsigned long));
	if (format == 'd' || format == 'i')
		len = ft_digits(va_arg(ap, int));
	if (format == 'u')
		len = ft_put_unsigned(va_arg(ap, unsigned int));
	if (format == 'x' || format == 'X')
		len = ft_digits_hexa(va_arg(ap, unsigned int), format);
	if (format == '%')
	{
		write(1, "%", 1);
		len += 1;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	if (str == NULL)
		return (0);
	len = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != 0)
	{
		if (str[i] == '%')
		{
			len += ft_printf_arg(ap, str[i + 1]);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			len += 1;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
