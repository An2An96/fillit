/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:36:10 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/10 21:36:11 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstremove(t_list **alst, t_list *el, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (*alst == el)
		{
			*alst = (*alst)->next;
			ft_lstdelone(&el, del);
			return (1);
		}
		else if ((*alst)->next == el)
		{
			(*alst)->next = el->next;
			ft_lstdelone(&el, del);
			return (1);
		}
		else
		{
			ft_lstremove(&((*alst)->next), el, del);
			return (1);
		}
	}
	return (0);
}
