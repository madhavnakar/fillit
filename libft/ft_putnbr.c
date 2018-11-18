/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:07:07 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/24 20:38:53 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		absval(int n)
{
	if (n < 0)
		write(1, "-", 1);
	return ((n < 0) ? (-1) * n : n);
}

static void		ft_putdigit(int n)
{
	char c;

	n = absval(n);
	c = n + '0';
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	int	next;

	if (-9 <= n && n <= 9)
		ft_putdigit(n);
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else
	{
		n = absval(n);
		next = n / 10;
		ft_putnbr(next);
		ft_putdigit(n - next * 10);
	}
}
