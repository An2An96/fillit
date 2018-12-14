/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschuppe <rschuppe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:35:06 by rschuppe          #+#    #+#             */
/*   Updated: 2018/12/14 14:43:57 by rschuppe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <limits.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	// #pragma unused (argc)
	// #pragma unused (argv)
	// printf("%d %d", CHAR_MIN, CHAR_MAX);
	// int fd;

	if (argc > 1)
	{
		char **tshift = NULL;
		int ntetr;
		validation(argv[1], tshift, &ntetr);
	}
	return (0);
}