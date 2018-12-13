#include "fillit.h"

void	find_result(char *result_map, char *tmp_map, char **figures, int figures_used)
{
	#pragma unused (result_map)
	#pragma unused (tmp_map)
	#pragma unused (figures)
	#pragma unused (figures_used)


	int cur_figure;

	cur_figure = 0;
	while (figures_used)
	{
		figures_used >>= 1;
		cur_figure++;
	}
}
