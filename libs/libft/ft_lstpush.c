/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:33:53 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/06 15:33:54 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, t_list *new)
{
	if (alst)
	{
		if (*alst)
		{
			if ((*alst)->next)
				ft_lstpush(&(*alst)->next, new);
			else
				(*alst)->next = new;
		}
		else
		{
			*alst = new;
		}
	}
}
