/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/17 18:03:07 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_ccount(char *buf)
{
	int	s;
	int	i;
	int j;

	i = -1;
	j = 0;
	while (buf[++i] != '\0')
	{
		if (buf[i] != '#')
			continue;
		s = 0;
		if (i + 1 < 20 && buf[i + 1] == '#')
			s++;
		if (i - 1 >= 0 && buf[i - 1] == '#')
			s++;
		if (i + 5 < 20 && buf[i + 5] == '#')
			s++;
		if (i - 5 >= 0 && buf[i - 5] == '#')
			s++;
		if (s > 1)
			j = 1;
		else if (s == 0)
			return (0);
	}
	return (j == 1);
}

static int	ft_chktetr(char *buf)
{
	int	i;
	int	counts;
	int	s;

	counts = 0;
	i = -1;
	while (buf[++i] != '\0')
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n' && buf[i] != '\0')
			|| ((i + 1) % 5 == 0 && buf[i] != '\n')
			|| i > 20 || counts > 4)
			return (0);
		if (buf[i] == '#')
			counts++;
	}
	s = ft_ccount(buf);
	return (s);
}

int			checkfile(int fd, int *terms)
{
	int		ret;
	char	buf[21];
	int		counts;

	ret = 1;
	counts = 0;
	*terms = 0;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		if (ret < 19)
			return (0);
		buf[19] = '\0';
		if (ret != 19 && buf[ret - 1] != '\n' && buf[ret - 1] != '\0')
			return (0);
		if (ft_chktetr(buf) == 0)
			return (0);
		*terms = *terms + 1;
	}
	close(fd);
	if (*terms > 0)
		return (1);
	else
		return (0);
}
