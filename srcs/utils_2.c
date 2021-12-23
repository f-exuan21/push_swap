#include <stdlib.h>
#include "../includes/push_swap.h"

void	copy_arr(int *dst, int *arr, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		dst[idx] = arr[idx];
		idx++;
	}
}

/*
** 삽입정렬
*/

int	*sort(int *arr, int size)
{
	int		i;
	int		j;
	int		*sorted_arr;
	int		tmp;

	sorted_arr = malloc(sizeof(int) * size);
	copy_arr(sorted_arr, arr, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted_arr[i] > sorted_arr[j])
			{
				tmp = sorted_arr[i];
				sorted_arr[i] = sorted_arr[j];
				sorted_arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (sorted_arr);
}

void	sort_simply(int *arr, int *sorted, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == sorted[j])
			{
				arr[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	check_dup_arr(int *arr, int idx, int find)
{
	int		i;

	i = 0;
	while (i < idx)
	{
		if (arr[i] == find)
		{
			error("[ERROR] Duplicated Parameters.");
		}
		i++;
	}
	return find;
}

char	**check_arg(int *argc, char *argv[])
{
	char	**tmp;
	int		i;

	tmp = argv;
	if (*argc == 1)
		exit(0);
	else if (*argc == 2)
	{
		i = 0;
		tmp = ft_split(argv[0], ' ');
		while (*(tmp + i) != NULL)
			i++;
		*argc = i + 1;
	}
	return (tmp);
}
