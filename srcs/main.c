/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/18 15:47:40 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

// void	resize_shifts(t_figures *figures, int map_size)
// {
// 	int i;
// 	int j;
// 	char *figure;

// 	i = 0;
// 	while (i < figures->count)
// 	{
// 		j = 0;
// 		while (j < 3)
// 		{
// 			figure = figures->figures[i][j];
// 			if (*figure < 0)
// 				*figure += (map_size - 4) * ((*figure / map_size - 1) - 1);
// 			else
// 				*figure += (map_size - 4) * (*figure / map_size - 1);
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
		map->size = 0;

		if (validation(argv[1], &figures, &(map->size)) > 0)
		{
			// for (int j = 0; j < figures.count; j++)
			// 	printf("[ %d, %d, %d ]", figures.figures[j][0], figures.figures[j][1], figures.figures[j][2]);
			map->map = ft_strnew(map->size * map->size);
			ft_memset(map->map, '.', map->size * map->size);
			while ((res = find_result(&map, &figures, 0)) == 0)
			{
				map->size++;
				free(map->map);
				map->map = ft_strnew(map->size * map->size);
				ft_memset(map->map, '.', map->size * map->size);
				// resize_shifts(&figures, map_size);
			}
		}
	}
	if (res < 0)
		ft_putstr("error");
	else
		show_result(map);
	return (0);
}
