/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:33:14 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/06 15:33:15 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_content(void *content, size_t content_size)
{
	ft_memdel(&content);
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_lst;
	t_list *tmp;

	new_lst = NULL;
	if (lst && f)
	{
		while (lst)
		{
			tmp = f(lst);
			if (tmp == NULL)
			{
				ft_lstdel(&new_lst, ft_free_content);
				break ;
			}
			ft_lstpush(&new_lst, tmp);
			lst = lst->next;
		}
	}
	return (new_lst);
}
