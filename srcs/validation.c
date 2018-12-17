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

// static int	ft_ccount(char *buf)
// {
// 	int	s;
// 	int	i;
// 	int j;

// 	i = -1;
// 	j = 0;
// 	while (buf[++i] != '\0')
// 	{
// 		if (buf[i] != '#')
// 			continue;
// 		s = 0;
// 		if (i + 1 < 20 && buf[i + 1] == '#')
// 			s++;
// 		if (i - 1 >= 0 && buf[i - 1] == '#')
// 			s++;
// 		if (i + 5 < 20 && buf[i + 5] == '#')
// 			s++;
// 		if (i - 5 >= 0 && buf[i - 5] == '#')
// 			s++;
// 		if (s > 1)
// 			j = 1;
// 		else if (s == 0)
// 			return (0);
// 	}
// 	return (j == 1);
// }

// static int	ft_chktetr(char *buf)
// {
// 	int	i;
// 	int	counts;
// 	int	s;
// 	int j;

// 	counts = 0;
// 	i = -1;
// 	while (buf[++i] != '\0')
// 	{
// 		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
// 			|| ((i + 1) % 5 == 0 && buf[i] != '\n')
// 			|| i > 20 || counts > 4)
// 			return (0);
// 		if (buf[i] == '#')
// 			counts++;
// 	}
// 	s = ft_ccount(buf);
// 	return (s);
// }

// static int	ft_chkfile(int fd, int *terms)
// {
// 	int		ret;
// 	char	buf[21];
// 	int		counts;

// 	ret = 1;
// 	counts = 0;
// 	*terms = 0;
// 	while (ret > 0)
// 	{
// 		if ((ret = read(fd, buf, 21)) <= 0)
// 			break ;
// 		if (ret < 20 && ret > 0)
// 			return (-1);
// 		buf[20] = '\0';
// 		if (buf[ret - 1] != '\n' && buf[ret - 1] != '\0')
// 			return (-1);
// 		if (ft_chktetr(buf) == 0)
// 			return (0);
// 		*terms = *terms + 1;
// 	}
// 	close(fd);
// 	if (*terms > 0)
// 		return (1);
// 	else
// 		return (0);
// }

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

int			validation(char *file, t_figures *tetrs, int *ntetr)
{
	int	i;
	int	fd;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	if (checkfile(fd, ntetr) == -1)
		return (0);
	if ((tetrs->figures = (char **)malloc(sizeof(char *) * *ntetr)) == NULL)
		return (0);
	i = 0;
	while (i++ < *ntetr)
	{
		if ((tetrs->figures[i] = (char *)malloc(sizeof(char))) == NULL)
		{
			while (--i)
				free(tetrs->figures[i]);
			free(tetrs->figures);
			return (0);
		}
	}
	if ((fd = open(file, O_RDONLY)) <= 0)
		return (0);
	ft_getshifts(fd, tetrs->figures);
	close(fd);
	return (1);
}
