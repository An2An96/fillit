/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:04:19 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/06 14:04:19 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int us_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		us_n = -n;
	}
	else
		us_n = n;
	if (us_n / 10)
		ft_putnbr_fd((int)(us_n / 10), fd);
	ft_putchar_fd((us_n % 10) + '0', fd);
}
