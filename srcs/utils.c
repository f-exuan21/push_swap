#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	error(char *str)
{
	write(1, str, ft_strlen(str));
	exit(-1);
}

void	ft_chkmax(unsigned long long n, int minus)
{
	if (n > INT_MAX && minus == 0)
		error("[ERROR] The number exceeded the maximum value.");
	else if (n - 1 > INT_MAX && minus == 1)
		error("[ERROR] The number exceeded the minimum value.");
}

int	ft_atoi(const char *str)
{
	long long		rst;
	int				minus;

	rst = 0;
	minus = 0;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		minus = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rst = rst * 10 + (*str - '0');
		str++;
	}
	ft_chkmax(rst, minus);
	if (minus)
		return (-rst);
	else
		return (rst);
}

int	is_digit(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-')
		idx++;
	while (str[idx])
	{
		if ('0' > str[idx] || '9' < str[idx])
			error("[ERROR] Invalid Parameters.\n");
		idx++;
	}
	return (1);
}
