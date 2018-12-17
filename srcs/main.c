/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/17 17:30:49 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	show_result(char *map)
{
	int i;

	if (map)
	{
		i = 0;
		while (map[i])
		{
			ft_putchar(map[i]);
			if (++i % 4 == 0)
				ft_putchar('\n');
		}
	}
}

int	main(int argc, char **argv)
{
	t_figures	figures;
	char		*map;
	int			map_size;
	int			res;

	res = -1;
	if (argc > 1)
	{
		if (validation(argv[1], &figures, &map_size) > 0)
		{
			figures.count = 3;
			map_size = 4;
			
			// for (int j = 0; j < figures.count; j++)
			// {
			// 	printf("[ %d, %d, %d ]", figures.figures[j][0], figures.figures[j][1], figures.figures[j][2]);
			// }
			
			map = ft_strnew(map_size * map_size);
			ft_memset(map, '.', map_size * map_size);
			while ((res = find_result(&map, map_size, &figures, 0)) == 0)
			{
				map_size++;
				free(map);
				map = ft_strnew(map_size * map_size);
				ft_memset(map, '.', 16);
			}
		}
	}
	if (res < 0)
		ft_putstr("error");
	else
		show_result(map);
	return (0);
}
