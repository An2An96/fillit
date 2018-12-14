/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:16:36 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/14 14:20:16 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	find_result(char *map, int map_size, t_figures *figures, int figures_used)
{
	#pragma unused (result_map)
	#pragma unused (tmp_map)
	#pragma unused (figures)
	#pragma unused (figures_used)


	int cur_figure;

	cur_figure = 0;
	while (figures_used & 1)
	{
		figures_used >>= 1;
		cur_figure++;
	}
	figures_used |= 1;
}
