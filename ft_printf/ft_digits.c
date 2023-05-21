/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:37:16 by juzheng           #+#    #+#             */
/*   Updated: 2023/03/20 15:37:17 by juzheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_toprint(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_toprint(n / 10);
		ft_toprint(n % 10);
	}
	else
	{
		n = n + 48;
		write(1, &n, 1);
	}
}

int	ft_digits(int n)
{
	long			c;
	int				i;

	i = 1;
	c = n;
	ft_toprint(n);
	if (c < 0)
	{
		i++;
		c = -c;
	}
	while (c >= 10)
	{
		c = c / 10;
		i++;
	}
	return (i);
}
