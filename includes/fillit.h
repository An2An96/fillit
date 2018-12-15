/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:09:34 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/15 13:26:55 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_fillit_map
{
	char *field;
	unsigned char field_size;
}				t_fillit_map;

typedef struct	s_figures
{
	char			**figures;
	unsigned char	count;
}				t_figures;

int		validation(char *file, t_figures *tetrs, int *ntetr);
int		find_result(char **map, int map_size, t_figures *figures, int figures_used);

#endif
