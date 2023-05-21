/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:40:36 by juzheng           #+#    #+#             */
/*   Updated: 2023/03/02 16:40:38 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static	void	ft_convert(uintptr_t n)
{
	if (n >= 16)
	{
		ft_convert(n / 16);
		ft_convert(n % 16);
	}
	else
	{
		if (n > 9)
			n = n + 87;
		else
			n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_put_ptr(uintptr_t n)
{
	unsigned long int	i;
	int					c;

	c = 1;
	i = n;
	if (!i)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_convert(n);
	while (i >= 16)
	{
		i = i / 16;
		c++;
	}
	return (c + 2);
}
