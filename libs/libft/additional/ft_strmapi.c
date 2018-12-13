/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:23:41 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 18:23:41 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	res = NULL;
	if (s && f)
	{
		res = ft_strnew(ft_strlen(s));
		if (res)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (res);
}
