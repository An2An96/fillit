/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:01:35 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/19 14:54:38 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		getmapsize(int terms)
{
	int	i;

	i = 2;
	while (terms * 4 > i * i)
		i++;
	return (i);
}

void	resize_shifts(t_figures *figures, int old_size, int new_size)
{
	int		i;
	int		j;
	char	*figure;

	i = 0;
	while (i < figures->count)
	{
		j = 0;
		while (j < 3)
		{
			figure = &(figures->figures[i][j]);
			if (old_size < new_size)
			{
				*figure += (ABS(new_size - old_size)
					* ((*figure / old_size) - (*figure < 0)));
			}
			else
			{
				*figure -= ((old_size - new_size)
					* ((*figure / old_size) - (*figure < 0)));
			}
			j++;
		}
		i++;
	}
}

void	show_result(const t_map *map)
{
	int i;

	if (map)
	{
		i = 0;
		while (map->map[i])
		{
			ft_putchar(map->map[i]);
			if (++i % map->size == 0)
				ft_putchar('\n');
		}
	}
}
