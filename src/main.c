/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:55:55 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:00:24 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a);
	stack_init(&b);
	if (argc < 2)
		return (0);
	if (!read_args(argc, argv, &a))
		error_exit(&a, &b);
	assign_indexes(&a);
	choose_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
