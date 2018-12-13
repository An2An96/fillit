/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:44:01 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/04 12:44:02 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int ch)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == ch)
			return (char*)(src + i);
		i++;
	}
	if (src[i] == ch)
		return (char*)(src + i);
	return (NULL);
}
