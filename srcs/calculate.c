/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/17 13:04:05 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_figure_to_map(char *map, int map_size, int pos, char *figure)
{
	int i;
	int start[2];
	int point[2];

	start[0] = pos % map_size;
	start[1] = pos / map_size;

	//	check
	i = 0;
	while (i < 3)
	{
		point[0] = start[0] + ABS(figure[i] % map_size);
		point[1] = start[1] + (figure[i] / map_size);
		if (point[0] < 0 || point[0] >= map_size
			|| point[1] < 0 || point[1] >= map_size
			|| map[(point[0] + point[1] * map_size)] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	set_figure_to_map(char *pos, char *figure, char ch)
{
	int i;

	i = 0;
	*pos = ch;
	while (i < 3)
	{
		*(pos + figure[i]) = ch;
		i++;
	}
	return (1);
}

int	find_result(char **map, int map_size, t_figures *figures, int figures_used)
{
	int res;
	int pos;
	int cur_figure;

	char *map_copy;

	cur_figure = 0;
	while ((figures_used >> cur_figure) & 1)
		if (++cur_figure >= figures->count)
			return (1);

	while (cur_figure < figures->count)	//	перебираем все фигуры
	{
		if (((figures_used >> cur_figure) & 1) == 0)	//	пропускаем использованные
		{
			pos = 0;
			while (pos < (map_size * map_size))	//	перебираем все свободные позиции
			{
				if ((*map)[pos] == '.')
				{
					if (check_figure_to_map((*map), map_size, pos, figures->figures[cur_figure]))
					{
						if ((map_copy = ft_strdup((*map))) == NULL)
							return (-1);
						set_figure_to_map(map_copy + pos, figures->figures[cur_figure], ('A' + cur_figure));
						res = find_result(&map_copy, map_size, figures, figures_used | (1 << cur_figure));
						if (res > 0)
						{
							free(*map);
							*map = map_copy;
							return (1);
						}
						else if (res < 0)
						{
							free(map_copy);
							return (-1);
						}
						else
						{
							free(map_copy);
						}
					}
				}
				pos++;
			}
		}
		cur_figure++;
	}
	return (0);
}
