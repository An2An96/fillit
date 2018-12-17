// int my_min(int result, void *el)
// {
// 	return (result > *((char*)el) ? *((char*)el) : result);
// }

// int my_max(int result, void *el)
// {
// 	return (result > *((char*)el) ? *((char*)el) : result);
// }

// int	ft_reduce(void *arr, size_t type_size, size_t n, int (*f)(int, void *))
// {
// 	int result;
// 	size_t i;

// 	result = 0;
// 	if (arr)
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			result = f(result, (arr + i * type_size));
// 			i++;
// 		}
// 	}
// 	return (result);
// }