/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:59:09 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:00:36 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_once(t_stack *s)
{
	t_node	*n;

	if (s->size < 2)
		return ;
	n = s->bottom;
	s->bottom = n->prev;
	if (s->bottom)
		s->bottom->next = NULL;
	else
		s->top = NULL;
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bottom = n;
	s->top = n;
}

void	rev_rotate_a(t_stack *a, int print)
{
	rev_rotate_once(a);
	if (print)
		print_str("rra\n");
}

void	rev_rotate_b(t_stack *b, int print)
{
	rev_rotate_once(b);
	if (print)
		print_str("rrb\n");
}

void	rev_rotate_ab(t_stack *a, t_stack *b, int print)
{
	rev_rotate_once(a);
	rev_rotate_once(b);
	if (print)
		print_str("rrr\n");
}
