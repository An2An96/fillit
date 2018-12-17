/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/17 18:02:17 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	getmapsize(int terms)
{
	int	i;

	i = 2;
	if (terms == 1)
		return (2);
	while (i * i != terms)
	{
		if (i < terms / 2)
			i++;
		else
		{
			terms++;
			i = 2;
		}
	}
	return (2 * i);
}
