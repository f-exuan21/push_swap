#include "../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*arr_a;
	int	*arr_b;
	int	idx;

	argc = check_arg(argc, argv);
	idx = 0;
	arr_a = malloc(sizeof(int) * (argc - 1));
	arr_b = malloc(sizeof(int) * (argc - 1));
	while (idx < argc - 1)
	{
		if (!is_digit(argv[idx + 1]))
			error("[ERROR] Invalid Parameters.\n");
		arr_a[idx] = ft_atoi(argv[idx + 1]);
		idx++;
	}
	if (check_dup_arr(arr_a, argc - 1))
		error("[ERROR] Duplicated Parameters.");
	if (argc >= 3 && argc <= 6)
		sort_arr(arr_a, arr_b, argc - 1);
	else
		heavy_sort_arr(arr_a, arr_b, argc - 1);
	free(arr_a);
	free(arr_b);
	return (0);
}
