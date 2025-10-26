/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:57:18 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:01:14 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_once(t_stack *s)
{
	t_node	*n;

	if (s->size < 2)
		return ;
	n = pop_top(s);
	push_bottom(s, n);
}

void	rotate_a(t_stack *a, int print)
{
	rotate_once(a);
	if (print)
		print_str("ra\n");
}

void	rotate_b(t_stack *b, int print)
{
	rotate_once(b);
	if (print)
		print_str("rb\n");
}

void	rotate_ab(t_stack *a, t_stack *b, int print)
{
	rotate_once(a);
	rotate_once(b);
	if (print)
		print_str("rr\n");
}
