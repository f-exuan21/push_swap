#include <unistd.h>

void	rra(int *arr, int cnt)
{
	int	idx;
	int	tmp;

	idx = cnt - 1;
	tmp = arr[idx];
	while (idx > 0)
	{
		arr[idx] = arr[idx - 1];
		idx--;
	}
	arr[0] = tmp;
	write(1, "rra\n", 4);
}

void	pa_all(int *arr_a, int *arr_b, int *cnt_a, int *cnt_b)
{
	int	i;
	int	idx;
	int	size;

	i = 0;
	size = *cnt_b;
	while (i++ < size)
	{
		idx = 0;
		while (idx < *cnt_a)
		{
			arr_a[*cnt_a - idx] = arr_a[*cnt_a - idx - 1];
			idx++;
		}
		arr_a[0] = arr_b[0];
		(*cnt_a)++;
		(*cnt_b)--;
		idx = 0;
		while (idx < *cnt_b)
		{
			arr_b[idx] = arr_b[idx + 1];
			idx++;
		}
		write(1, "pa\n", 3);
	}
}

void	pb(int *arr_a, int *arr_b, int *cnt_a, int *cnt_b)
{
	int	idx;

	idx = 0;
	while (idx < *cnt_b)
	{
		arr_b[*cnt_b - idx] = arr_b[*cnt_b - idx - 1];
		idx++;
	}
	arr_b[0] = arr_a[0];
	(*cnt_b)++;
	(*cnt_a)--;
	idx = 0;
	while (idx < *cnt_a)
	{
		arr_a[idx] = arr_a[idx + 1];
		idx++;
	}
	write(1, "pb\n", 3);
}

void	sa(int *arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[1];
	arr[1] = tmp;
	write(1, "sa\n", 3);
}

void	ra(int *arr, int cnt)
{
	int	idx;
	int	tmp;

	idx = 0;
	tmp = arr[0];
	while (idx < cnt - 1)
	{
		arr[idx] = arr[idx + 1];
		idx++;
	}
	arr[idx] = tmp;
	write(1, "ra\n", 3);
}
