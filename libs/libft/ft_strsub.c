/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:32:37 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 18:32:37 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	res = NULL;
	if (s && (start + len) <= ft_strlen(s))
	{
		res = ft_strnew(len);
		if (res)
		{
			i = 0;
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
		}
	}
	return (res);
}
