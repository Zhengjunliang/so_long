/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:35:08 by juzheng           #+#    #+#             */
/*   Updated: 2023/03/20 15:35:09 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_convert(n / 16, format);
		ft_convert(n % 16, format);
	}
	else if (n > 9)
	{
		if (format == 'x')
			n = n + 87;
		else
			n = n + 55;
		write(1, &n, 1);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_digits_hexa(unsigned int n, char format)
{
	unsigned int	i;
	int				c;

	c = 1;
	i = n;
	ft_convert(n, format);
	while (i >= 16)
	{
		i = i / 16;
		c++;
	}
	return (c);
}
