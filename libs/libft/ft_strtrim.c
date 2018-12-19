/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:46:19 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/05 18:46:19 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_find_body_pos(const char *s, int *start, int *end)
{
	int i;

	*start = -1;
	*end = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
		{
			if (*start == -1)
				*start = i;
			else
				*end = i + 1;
		}
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	int		start;
	int		end;

	res = NULL;
	if (s)
	{
		ft_find_body_pos(s, &start, &end);
		res = ft_strnew(end - start);
		if (res)
			ft_strncpy(res, s + start, end - start);
	}
	return (res);
}
