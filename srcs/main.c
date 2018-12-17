/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/17 15:10:45 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	#pragma unused (argv)

	t_figures	figures;
	char		*map;
	int			map_size;
	int			res;

	res = -1;
	if (argc > 1)
	{
		map_size = 4;

		figures.figures = (char**)malloc(3 * sizeof(char*));
		/*
			##..
			.##.
			....
			....
		*/
		figures.figures[0] = (char*)malloc(3 * sizeof(char));
		figures.figures[0][0] = 1;
		figures.figures[0][1] = 5;
		figures.figures[0][2] = 6;
		/*
			#...
			#...
			#...
			#...
		*/
		figures.figures[2] = (char*)malloc(3 * sizeof(char));
		figures.figures[2][0] = 4;
		figures.figures[2][1] = 8;
		figures.figures[2][2] = 12;
		/*
			##..
			.#..
			.#..
			....
		*/
		figures.figures[1] = (char*)malloc(3 * sizeof(char));
		figures.figures[1][0] = 1;
		figures.figures[1][1] = 5;
		figures.figures[1][2] = 9;

		figures.count = 3;

		// if (validation(argv[1], &figures, &map_size) > 0)
		// {
		map = ft_strnew(map_size * map_size);
		ft_memset(map, '.', map_size * map_size);
		while ((res = find_result(&map, map_size, &figures, 0)) == 0)
		{
			map_size++;
			free(map);
			map = ft_strnew(map_size * map_size);
			ft_memset(map, '.', 16);
		}
		// }
	}
	if (res < 0)
		ft_putstr("error");
	else
		show_result(map);
	return (0);
}
