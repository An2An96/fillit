/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/18 16:48:32 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_figure_to_map(const t_map *map, int pos, char *figure)
{
	int i;
	int start[2];
	int point[2];

	start[0] = pos % map->size;
	start[1] = pos / map->size;
	i = 0;
	while (i < 3)
	{
		point[0] = start[0] + (figure[i] % 4) + (4 * (figure[i] < 0));
		point[1] = start[1] + (figure[i] / 4) - (figure[i] < 0);
		if (point[0] < 0 || point[0] >= map->size
			|| point[1] < 0 || point[1] >= map->size
			|| map->map[(point[0] + point[1] * map->size)] != '.')
			return (0);
		i++;
	}
	return (1);
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

static t_map	*copy_map(t_map *map)
{
	t_map	*new;
	char	*buf;

	new = NULL;
	if (map)
	{
		new = (t_map*)malloc(sizeof(t_map));
		if (!new)
			exit(1);
		if ((new->map = ft_strdup(map->map)))
			new->size = map->size;
		else
			ft_memdel((void**)(&new));
	}
	return (new);
}

static int		handle_result(int result, t_map **map, t_map *map_copy)
{
	if (result > 0)
	{
		free(*map);
		*map = map_copy;
	}
	else
		free(map_copy);
	return (result);
}

int				find_result(t_map **map, t_figures *data, long long used)
{
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
		while (++pos < ((*map)->size * (*map)->size))
		{
			if ((*map)->map[pos] != '.'
			|| !check_figure_to_map(*map, pos, data->figures[cur_tet]))
				continue;
			map_c = copy_map(*map);
			set_figure(map_c, pos, data->figures[cur_tet], ('A' + cur_tet));
			if (handle_result(find_result(&map_c, data,
				used | (1 << cur_tet)), map, map_c))
				return (1);
		}
	}
	return (0);
}
