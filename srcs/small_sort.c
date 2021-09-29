#include "../includes/push_swap.h"

/*
** arr이 순차적으로 정렬되어 있는지 수시로 확인
*/

int	check_arr(int *arr, int cnt)
{
	int	idx;

	idx = 1;
	while (idx < cnt)
	{
		if (arr[idx] < arr[idx - 1])
			return (1);
		idx++;
	}
	return (0);
}

int	find_min(int *arr, int cnt)
{
	int	min;
	int	idx;

	min = arr[0];
	idx = 1;
	while (idx < cnt)
	{
		if (arr[idx] < min)
			min = arr[idx];
		idx++;
	}
	return (min);
}

/*
** 맨 위 숫자를 기준으로 한 칸 아래 숫자와 맨 아래 숫자를 비교한다.
** 0 : sa
** 1 : ra
*/

int	compare_numbers(int *arr, int cnt)
{
	if (arr[0] > arr[1] && arr[0] > arr[cnt - 1])
	{
		if (arr[1] > arr[cnt - 1])
			return (0);
		else
			return (1);
	}
	else if (arr[0] > arr[1] && arr[0] < arr[cnt - 1])
		return (0);
	else if (arr[0] < arr[1] && arr[0] > arr[cnt - 1])
		return (1);
	else
		return (1);
}

void	sort_arr(int *arr_a, int *arr_b, int cnt_a)
{
	int	cnt_b;
	int	min;
	int	*tmp;

	cnt_b = 0;
	sort_simply(arr_a, tmp = sort(arr_a, cnt_a), cnt_a);
	free(tmp);
	while (check_arr(arr_a, cnt_a))
	{
		min = find_min(arr_a, cnt_a);
		if (arr_a[0] == arr_a[1] + 1 || arr_a[1] == arr_a[cnt_a - 1] + 1)
			sa(arr_a);
		else if (min == arr_a[0])
			pb(arr_a, arr_b, &cnt_a, &cnt_b);
		else if (min == arr_a[cnt_a - 1])
			rra(arr_a, cnt_a);
		else
		{
			if (compare_numbers(arr_a, cnt_a))
				ra(arr_a, cnt_a);
			else
				sa(arr_a);
		}
	}
	pa_all(arr_a, arr_b, &cnt_a, &cnt_b);
}
