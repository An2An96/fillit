/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/19 14:24:34 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tetr_to_map(const t_map *map, int *pos, char *tetr)
{
	int i;
	int s[2];
	int p[2];
	int shift[2];

	s[0] = *pos % map->size;
	s[1] = *pos / map->size;
	i = -1;
	shift[1] = 0;
	while (++i < 3)
	{
		shift[0] = 0;
		p[0] = s[0] + (tetr[i] % map->size) + (map->size * (tetr[i] < 0));
		p[1] = s[1] + (tetr[i] / map->size) - (tetr[i] < 0);
		if (p[1] >= map->size)
			return (-1);
		if (p[1] < 0 || p[0] >= map->size)
			shift[0] = (s[1] - (p[1] < 0 ? p[1] : -1)) * map->size - *pos;
		if (!shift[0] && map->map[(p[0] + p[1] * map->size)] != '.')
			return (0);
		if (shift[0] > shift[1])
			shift[1] = shift[0];
	}
	*pos += shift[1] ? (shift[1] - 1) : 0;
	return (shift[1] == 0);
}

static void		set_tetr_to_map(const t_map *map, int pos, char *tetr, char ch)
{
	map->map[pos] = ch;
	map->map[pos + tetr[0]] = ch;
	map->map[pos + tetr[1]] = ch;
	map->map[pos + tetr[2]] = ch;
}

int				find_result(t_map *map, t_figures *data, long long used)
{
	int		res;
	int		pos;
	int		cur_tet;

	cur_tet = ((used == (0xFFFFFFFF >> (32 - data->count))) ? 0xFF : 0) - 1;
	while (++cur_tet < data->count)
	{
		if (((used >> cur_tet) & 1) != 0)
			continue;
		pos = -1;
		while (++pos < (map->size * map->size))
		{
			if (map->map[pos] != '.'
			|| !(res = check_tetr_to_map(map, &pos, data->figures[cur_tet])))
				continue;
			if (res < 0)
				break ;
			set_tetr_to_map(map, pos, data->figures[cur_tet], ('A' + cur_tet));
			if (find_result(map, data, used | (1 << cur_tet)))
				return (1);
			set_tetr_to_map(map, pos, data->figures[cur_tet], '.');
		}
	}
	return (cur_tet == 0xFF);
}

int				fillit(char *filename)
{
	t_figures	figures;
	t_map		map;
	int			res;

	res = 0;
	if (filename)
	{
		if (validation(filename, &figures, &(map.size)) > 0)
		{
			map.map = ft_strnew(map.size * map.size);
			ft_memset(map.map, '.', map.size * map.size);
			while ((res = find_result(&map, &figures, 0)) == 0)
			{
				map.size++;
				free(map.map);
				map.map = ft_strnew(map.size * map.size);
				ft_memset(map.map, '.', map.size * map.size);
				resize_shifts(&figures, map.size - 1, map.size);
			}
			if (res)
				show_result(&map);
		}
	}
	return (res == 1);
}
