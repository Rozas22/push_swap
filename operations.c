#include "operations.h"

void	sa(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	ra(int *a)
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = a[2];
	a[2] = temp;
}

void	rra(int *a)
{
	int	temp;

	temp = a[2];
	a[2] = a[1];
	a[1] = a[0];
	a[0] = temp;
}
