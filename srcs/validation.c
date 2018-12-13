/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anorjen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:56:05 by anorjen           #+#    #+#             */
/*   Updated: 2018/12/10 14:56:05 by anorjen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_chkterm(char *buf)
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
		if (ft_chkterm(buf) == -1)
			return (-1);
		*terms = *terms + 1;
	}
	if (*terms > 0)
		return (1);
	else
		return (-1);
}

static int	ft_binterm(int fd, int *fig, int nterms)
{
	int		k;
	char	buf[21];
	int		i;

	k = 0;
	while (k++ < nterms)
	{
		ft_bzero(&fig[k], sizeof(int));
		if (read(fd, buf, 21) <= 0)
			return (-1);
		buf[20] = '\0';
		i = 0;
		while (buf[i] != '\0')
		{
			fig[i] |= (buf[i] == '#');
			if (buf[i] != '\n')
				fig[i] = fig[i] << 1;
		}
	}
	return (1);
}

int			validation(int fd, int *fig)
{
	int	nterms;
	int	i;

	if (ft_chkfile(fd, &nterms) == -1)
		return (-1);
	if ((fig = (int *)malloc(sizeof(int) * nterms)) == NULL)
		return (-1);
	ft_bzero(fig, sizeof(int) * nterms);
	i = 0;
	if (ft_binterm(fd, fig, nterms) == -1)
		return (-1);
	return (1);
}
