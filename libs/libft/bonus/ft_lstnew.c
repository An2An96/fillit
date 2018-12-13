/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:21:40 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/06 14:21:41 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	res = ft_memalloc(sizeof(t_list));
	if (res)
	{
		if (content)
		{
			res->content = ft_memalloc(content_size);
			if (res->content)
			{
				ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
			}
			else
				res->content_size = 0;
		}
		else
		{
			res->content = NULL;
			res->content_size = 0;
		}
		res->next = NULL;
	}
	return (res);
}
