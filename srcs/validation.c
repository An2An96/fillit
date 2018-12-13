/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/10 14:56:05 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_chktetr(char *buf)
{
	int	i;
	int	counts;

	counts = 0;
	i = 0;
	while (buf[i++] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (-1);
		if (buf[i] == '#' && buf[i - 1] != '#' && buf[i + 1] != '#'
			&& buf[i + 5] != '#' && buf[i - 5] != '#')
			return (-1);
		if (buf[i] == '#')
			counts++;
	}
	if (counts != 4)
		return (-1);
	return (1);
}

static int	ft_chkfile(int fd, int *terms)
{
	int		ret;
	char	buf[21];
	int		counts;

	ret = 1;
	counts = 0;
	*terms = 0;
	while (ret > 0)
	{
		if ((ret = read(fd, buf, 21)) <= 0)
			break ;
		if (ret < 20 && ret > 0)
			return (-1);
		buf[20] = '\0';
		if (buf[ret] != '\n' && buf[ret] != '\0')
			return (-1);
		if (ft_chktetr(buf) == -1)
			return (-1);
		*terms = *terms + 1;
	}
	if (*terms > 0)
		return (1);
	else
		return (-1);
}

static void	ft_left(char *buf, char *shift)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = -1;
	while (buf[i] != '\0')
	{
		if (j != -1 && buf[i] == '#')
		{
			//~ if (i - j < 0)
				//~ shift[k] = (char)(i - j + 1);
			//~ else if (i - j > 4)
				//~ shift[k] = (char)(i - j - 1);
			//~ else
			shift[k] = (char)(i - j);
			k++;
		}
		if (buf[i] == '#' && j == -1)
			j = i;
		if ((i + 1) / 5 == 3)
			i = i % 5 + 1;
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
		buf[20] = '\0';
		ft_left(buf, tshift[i]);
		i++;
	}
}

int			validation(char *file, char **tshift, int *ntetr)
{
	int	i;
	int	fd;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (-1);
	if (ft_chkfile(fd, ntetr) == -1)
		return (-1);
	if ((tshift = (char **)malloc(sizeof(char *) * *ntetr)) == NULL)
		return (-1);
	i = 0;
	while (i < *ntetr)
	{
		if ((tshift[i] = (char *)malloc(sizeof(char))) == NULL)
		{
			while (--i)
				free(tshift[i]);
			free(tshift);
			return (-1);
		}
	}
	ft_getshifts(fd, tshift);
	close(fd);
	return (1);
}
