/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:09:32 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 17:09:33 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	char			*res;

	res = malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			res[i] = 0;
			i++;
		}
		return ((void*)res);
	}
	return (NULL);
}
