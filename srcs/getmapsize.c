/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmapsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/18 13:36:37 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	getmapsize(int terms)	//	переписать!
{
	int	i;

	i = 2;
	if (terms == 1)
		return (2);
	else if (terms == 2)
		return (3);
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
