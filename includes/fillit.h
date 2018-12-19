/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:09:34 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/19 14:11:28 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_map
{
	char	*map;
	int		size;
}				t_map;

typedef struct	s_figures
{
	char			**figures;
	unsigned char	count;
}				t_figures;

int				fillit(char *filename);
int				checkfile(int fd, int *terms);
int				validation(char *file, t_figures *tetrs, int *ntetr);
void			resize_shifts(t_figures *figures, int old_size, int new_size);
int				getmapsize(int terms);
int				find_result(t_map *map, t_figures *data, long long used);
void			show_result(const t_map *map);

#endif
