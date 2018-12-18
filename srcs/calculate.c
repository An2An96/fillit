/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/18 13:21:19 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_figure_to_map(char *map, int map_size, int pos, char *figure, int figure_num)
{
	int i;
	int start[2];
	int point[2];

	start[0] = pos % map_size;
	start[1] = pos / map_size;
	i = 0;
	
	// if (figure_num == 4 && start[0] == 4 && start[1] == 5)
	// 	printf("stop");
	while (i < 3)
	{
		int c = figure[i];
		point[0] = start[0] + (figure[i] % 4);
		point[1] = start[1] + (figure[i] / 4);
		if (figure[i] < 0)
		{
			point[0] += 4;
			point[1]--;
		}
		int d = point[0] + point[1] * map_size;
		char b = map[(point[0] + point[1] * map_size)];
		if (point[0] < 0 || point[0] >= map_size
			|| point[1] < 0 || point[1] >= map_size
			|| map[(point[0] + point[1] * map_size)] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void	set_figure_to_map(char *pos, int map_size, char *figure, char ch)
{
	int i;
	char shift;

	i = 0;
	*pos = ch;

	while (i < 3)
	{
		// if (map_size > 4)
		// 	printf("stop");
		if (figure[i] < 0)
			shift = figure[i] + ((map_size - 4) * ((figure[i] / 4) - 1));
		else
			shift = figure[i] + ((map_size - 4) * (figure[i] / 4));
		*(pos + shift) = ch;
		i++;
	}
}

int			find_result(
	char **map, int map_size, t_figures *figures, long long figures_used)
{
	int		res;
	int		pos;
	int		cur_figure;
	char	*map_copy;

	if (figures_used == (0xFFFFFFFF >> (32 - figures->count)))
		return (1);
	cur_figure = -1;
	while (++cur_figure < figures->count)
	{
		if (((figures_used >> cur_figure) & 1) == 0)
		{
			pos = -1;
			while (++pos < (map_size * map_size))
			{
				if ((*map)[pos] != '.')
					continue;
				if (check_figure_to_map(
					(*map), map_size, pos, figures->figures[cur_figure], cur_figure))
				{
					if ((map_copy = ft_strdup((*map))) == NULL)
						return (-1);
					set_figure_to_map(map_copy + pos, map_size,
						figures->figures[cur_figure], ('A' + cur_figure));
					res = find_result(&map_copy, map_size,
						figures, figures_used | (1 << cur_figure));
					if (res > 0)
					{
						free(*map);
						*map = map_copy;
						return (1);
					}
					free(map_copy);
					if (res < 0)
						return (-1);
				}
			}
		}
	}
	return (0);
}
