#include <stdio.h>
#include "operations.h"
#include "utils.h"

int	main(void)
{
	int	a[3];
	int	size;

	size = 3;
	a[0] = 1;
	a[1] = 3;
	a[2] = 2;
	printf("Initial stack: ");
	print_stack(a, size);

	sort_three(a);

	printf("Sorted stack: ");
	print_stack(a, size);

	return (0);
}
