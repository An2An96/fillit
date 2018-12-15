/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/15 13:36:46 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	#pragma unused (argv)

	if (argc > 1)
	{
		// int ntetr;
		// t_figures figures;
		// validation(argv[1], &figures, &ntetr);

		int map_size = 4;
		char *map = ft_strnew(map_size * map_size);
		ft_memset(map, '.', 16);

		t_figures figures;
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
		figures.figures[1] = (char*)malloc(3 * sizeof(char));
		figures.figures[1][0] = 4;
		figures.figures[1][1] = 8;
		figures.figures[1][2] = 12;
		/*
			##..
			.#..
			.#..
			....
		*/
		figures.figures[2] = (char*)malloc(3 * sizeof(char));
		figures.figures[2][0] = 1;
		figures.figures[2][1] = 5;
		figures.figures[2][2] = 9;

		figures.count = 3;

		find_result(&map, map_size, &figures, 0);
		printf("%s", map);
	}
	return (0);
}