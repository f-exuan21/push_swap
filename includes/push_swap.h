#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

/*
** utils
*/

int		ft_atoi(const char *str);
int		is_digit(char *str);
void	error(char *str);
int		*sort(int *arr, int size);

/*
** main
*/

void	sort_arr(int *arr_a, int *arr_b, int cnt_a);
void	heavy_sort_arr(int *arr_a, int *arr_b, int cnt_a);
void	rra(int *arr, int cnt);
void	pa_all(int *arr_a, int *arr_b, int *cnt_a, int *cnt_b);
void	pb(int *arr_a, int *arr_b, int *cnt_a, int *cnt_b);
void	sa(int *arr);
void	ra(int *arr, int cnt);
void	sort_simply(int *arr, int *sorted, int size);

#endif