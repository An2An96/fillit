/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/18 19:03:01 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_figure_to_map(const t_map *map, int pos, char *figure)
{
	int i;
	int start[2];
	int point[2];
	int result_shift;
	int tmp;

	start[0] = pos % map->size;
	start[1] = pos / map->size;
	i = 0;
	result_shift = 0;
	while (i < 3)
	{
		tmp = 0;
		point[0] = start[0] + (figure[i] % 4) + (4 * (figure[i] < 0));
		point[1] = start[1] + (figure[i] / 4) - (figure[i] < 0);
		if (point[0] < 0 || point[1] >= map->size)
			return (-1);
		if (point[1] < 0 || point[0] >= map->size)
			tmp = (start[1] - (point[1] < 0 ? point[1] : -1)) * map->size - pos;
		if (!tmp && map->map[(point[0] + point[1] * map->size)] != '.')
			return (1);
		if (tmp > result_shift)
			result_shift = tmp;
		i++;
	}
	return (result_shift);
}

static void		set_figure(t_map *map, int pos, char *figure, char ch)
{
	char	shift;

	map->map[pos] = ch;
	shift = figure[0] + ((map->size - 4) * ((figure[0] / 4) - (figure[0] < 0)));
	map->map[pos + shift] = ch;
	shift = figure[1] + ((map->size - 4) * ((figure[1] / 4) - (figure[1] < 0)));
	map->map[pos + shift] = ch;
	shift = figure[2] + ((map->size - 4) * ((figure[2] / 4) - (figure[2] < 0)));
	map->map[pos + shift] = ch;
}

int				find_result(t_map *map, t_figures *data, long long used)
{
	int		res;
	int		pos;
	int		cur_tet;
	t_map	*map_c;

	if (used == (0xFFFFFFFF >> (32 - data->count)))
		return (1);
	cur_tet = -1;
	while (++cur_tet < data->count)
	{
		if (((used >> cur_tet) & 1) != 0)
			continue;
		pos = -1;
		while (++pos < (map->size * map->size))
		{
			if (map->map[pos] != '.')
				continue;
			if ((res = check_figure_to_map(map, pos, data->figures[cur_tet])))
			{
				if (res > 0)
				{
					pos += res - 1;
					continue;
				}
				break ;
			}
			set_figure(map, pos, data->figures[cur_tet], ('A' + cur_tet));
			if (find_result(map, data, used | (1 << cur_tet)))
				return (1);
			set_figure(map, pos, data->figures[cur_tet], '.');
		}
	}
	return (0);
}
