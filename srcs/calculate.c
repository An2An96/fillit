/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/14 17:13:57 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int my_min(int result, void *el)
// {
// 	return (result > *((char*)el) ? *((char*)el) : result);
// }

// int my_max(int result, void *el)
// {
// 	return (result > *((char*)el) ? *((char*)el) : result);
// }

// int	ft_reduce(void *arr, size_t type_size, size_t n, int (*f)(int, void *))
// {
// 	int result;
// 	size_t i;

// 	result = 0;
// 	if (arr)
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			result = f(result, (arr + i * type_size));
// 			i++;
// 		}
// 	}
// 	return (result);
// }

int	check_figure_to_map(char *map, int map_size, int pos, char *figure)
{
	int i;
	int idx;
	int start[2];
	int point[2];

	start[0] = pos % map_size;
	start[1] = pos / map_size;

	//	check
	i = 0;
	while (i < 3)
	{
		point[0] = start[1] + (figure[i] / map_size);
		point[1] = start[0] + ABS(figure[i] % map_size);
		if (point[0] < 0 || point[0] >= map_size
			|| point[1] < 0 || point[1] >= map_size
			|| map[(point[0] * map_size + point[1])] != '.')
			return (0);
	}
	return (1);
}

int	set_figure_to_map(char *pos, char *figure, char ch)
{
	int i;

	i = 0;
	while (i < 3)
	{
		map[(pos + figure[i])] = ch;
		i++;
	}
	return (1);
}

int	find_result(char *map, int map_size, t_figures *figures, int figures_used)
{
	int pos;
	int cur_figure;

	cur_figure = 0;
	while ((figures_used >> cur_figure) & 1)
		if (++cur_figure >= figures->count)
			return (1);

	while (cur_figure < figures->count)	//	перебираем все фигуры
	{
		if ((figures_used >> cur_figure) & 1)	//	пропускаем использованные
			continue;

		pos = 0;
		while (pos < map_size)	//	перебираем все свободные позиции
		{
			if (map[pos] != '.')
				continue;
			if (check_figure_to_map(map, map_size, pos, figures->figures[cur_figure]))
			{
				set_figure_to_map(map[pos], figures->figures[cur_figure], ('A' + cur_figure));
				if (find_result(map, map_size, figures, figures_used | (1 << cur_figure)))
					return (1);
			}
		}
	}
	return (0);
}
