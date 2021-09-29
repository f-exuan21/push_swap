#include "../includes/push_swap.h"

int	get_max_bits(int size)
{
	int	idx;
	int	max_num;
	int	max_bits;

	idx = 0;
	max_bits = 0;
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_using_bits(int *arr_a, int *arr_b, int cnt_a, int cnt_b)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (i < get_max_bits(cnt_a))
	{
		j = 0;
		size = cnt_a;
		while (j < size)
		{
			if (((arr_a[0] >> i) & 1) == 1)
				ra(arr_a, cnt_a);
			else
				pb(arr_a, arr_b, &cnt_a, &cnt_b);
			j++;
		}
		pa_all(arr_a, arr_b, &cnt_a, &cnt_b);
		i++;
	}
	pa_all(arr_a, arr_b, &cnt_a, &cnt_b);
}

void	heavy_sort_arr(int *arr_a, int *arr_b, int cnt_a)
{
	int	cnt_b;
	int	*tmp;

	cnt_b = 0;
	tmp = sort(arr_a, cnt_a);
	sort_simply(arr_a, tmp, cnt_a);
	if (!check_arr(arr_a, cnt_a))
		exit(1);
	free(tmp);
	sort_using_bits(arr_a, arr_b, cnt_a, cnt_b);
}
