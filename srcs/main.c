/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/18 21:06:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_figures	figures;
	t_map		*map;
	int			res;

	res = -1;
	if (argc > 1)
	{
		map = (t_map*)malloc(sizeof(t_map));
		map->map = NULL;
		if (validation(argv[1], &figures, &(map->size)) > 0)
		{
			map->map = ft_strnew(map->size * map->size);
			ft_memset(map->map, '.', map->size * map->size);
			while ((res = find_result(map, &figures, 0)) == 0)
			{
				map->size++;
				free(map->map);
				map->map = ft_strnew(map->size * map->size);
				ft_memset(map->map, '.', map->size * map->size);
				resize_shifts(&figures, map->size - 1, map->size);
			}
		}
	}
	show_result(res, map);
	return (0);
}
