/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:42:12 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 12:55:49 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int diff;

	while (*s1 || *s2)
	{
		diff = (unsigned char)*s1 - (unsigned char)*s2;
		if (diff)
			return (diff);
		s1++;
		s2++;
	}
	return (0);
}
