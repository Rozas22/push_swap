#include <stdio.h>
#include "operations.h"

void	sort_three(int *a)
{
	int	first;
	int	second;
	int	third;

	first = a[0];
	second = a[1];
	third = a[2];

	if (first > second && second > third)
	{
		sa(a);
		printf("sa\n");
		rra(a);
		printf("rra\n");
	}
	else if (first > third && third > second)
	{
		ra(a);
		printf("ra\n");
	}
	else if (second > first && first > third)
	{
		rra(a);
		printf("rra\n");
	}
	else if (second > third && third > first)
	{
		sa(a);
		printf("sa\n");
		ra(a);
		printf("ra\n");
	}
	else if (third > first && first > second)
	{
		sa(a);
		printf("sa\n");
	}
}

