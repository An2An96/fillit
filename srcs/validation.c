/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/14 14:51:26 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_left(char *buf, char *shift)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = -1;
	while ((i + 1) % 5)
	{
		if (j != -1 && buf[i] == '#')
		{
			shift[k] = (char)(i - j);
			if (shift[k] < 0 && shift[k] / 4 == 0)
				shift[k] = -1;
			shift[k] = shift[k] - shift[k] / 4;
			k++;
		}
		if (buf[i] == '#' && j == -1)
			j = i;
		if ((i + 1) / 5 == 3)
			i = i % 5 + 1;
		else
			i = i + 5;
	}
}

static void	ft_getshifts(int fd, char **tshift)
{
	int		ret;
	char	buf[21];
	int		i;

	ret = 1;
	i = 0;
	while (ret > 0)
	{
		if ((ret = read(fd, buf, 21)) <= 0)
			break ;
		buf[19] = '\0';
		ft_left(buf, tshift[i]);
		i++;
	}
}

static int	ft_getmem(t_figures *tetrs, int ntetr)
{
	int	i;

	if ((tetrs->figures = (char **)malloc(sizeof(char *) * ntetr)) == NULL)
		return (0);
	i = -1;
	while (++i < ntetr)
	{
		if ((tetrs->figures[i] = (char *)malloc(sizeof(char) * 3)) == NULL)
		{
			while (--i)
				free(tetrs->figures[i]);
			free(tetrs->figures);
			return (0);
		}
	}
	return (1);
}

int			validation(char *file, t_figures *tetrs, int *mapsize)
{
	int	fd;
	int ntetr;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	if (checkfile(fd, &ntetr) == 0)
		return (0);
	if (ft_getmem(tetrs, ntetr) != 1)
		return (0);
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	ft_getshifts(fd, tetrs->figures);
	close(fd);
	tetrs->count = ntetr;
	*mapsize = getmapsize(ntetr);
	return (1);
}
