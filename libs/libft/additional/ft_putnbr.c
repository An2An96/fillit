/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:11:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/06 13:11:14 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int us_n;

	if (n < 0)
	{
		ft_putchar('-');
		us_n = -n;
	}
	else
		us_n = n;
	if (us_n / 10)
		ft_putnbr((int)(us_n / 10));
	ft_putchar((us_n % 10) + '0');
}
