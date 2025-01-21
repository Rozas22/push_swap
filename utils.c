#include <stdio.h>

void	print_stack(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");
}
