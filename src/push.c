/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:56:23 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:02:18 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b, int print)
{
	t_node	*n;

	n = pop_top(b);
	if (n)
		push_top(a, n);
	if (print)
		print_str("pa\n");
}

void	push_b(t_stack *a, t_stack *b, int print)
{
	t_node	*n;

	n = pop_top(a);
	if (n)
		push_top(b, n);
	if (print)
		print_str("pb\n");
}
