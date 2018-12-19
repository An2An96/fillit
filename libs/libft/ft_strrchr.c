/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:57:48 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/04 12:57:49 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int ch)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (src[i] != '\0')
	{
		if (src[i] == ch)
			res = (char*)(src + i);
		i++;
	}
	if (src[i] == ch)
		res = (char*)(src + i);
	return (res);
}
