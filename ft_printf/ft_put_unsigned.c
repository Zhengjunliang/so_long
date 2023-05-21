/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:29:52 by juzheng           #+#    #+#             */
/*   Updated: 2023/03/20 15:29:56 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert(unsigned int n)
{
	if (n >= 10)
	{
		ft_convert(n / 10);
		ft_convert(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_put_unsigned(unsigned int n)
{
	long	i;
	int		c;

	c = 1;
	i = n;
	ft_convert(n);
	while (i >= 10)
	{
		i = i / 10;
		c++;
	}
	return (c);
}
