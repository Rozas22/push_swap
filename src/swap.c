/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:58:28 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:01:09 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top_two(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	if (s->size < 2)
		return ;
	a = s->top;
	b = a->next;
	a->next = b->next;
	if (b->next)
		b->next->prev = a;
	else
		s->bottom = a;
	b->prev = NULL;
	b->next = a;
	a->prev = b;
	s->top = b;
}

void	swap_a(t_stack *a, int print)
{
	swap_top_two(a);
	if (print)
		print_str("sa\n");
}

void	swap_b(t_stack *b, int print)
{
	swap_top_two(b);
	if (print)
		print_str("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b, int print)
{
	swap_top_two(a);
	swap_top_two(b);
	if (print)
		print_str("ss\n");
}
