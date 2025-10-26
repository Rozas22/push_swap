/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:58:43 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/26 18:19:33 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	choose_chunk(int n)
{
	if (n <= 100)
		return (18);
	return (40);
}

static int	capped_hi(int lo, int chunk, int n)
{
	int	hi;

	hi = lo + chunk - 1;
	if (hi >= n)
		hi = n - 1;
	return (hi);
}

static void	push_chunks(t_stack *a, t_stack *b)
{
	int	n;
	int	chunk;
	int	lo;
	int	pos;

	n = a->size;
	chunk = choose_chunk(n);
	lo = 0;
	while (a->size > 0)
	{
		pos = find_pos_chunk(a, lo, capped_hi(lo, chunk, n));
		if (pos == -1)
		{
			lo += chunk;
			continue ;
		}
		rot_to_top(a, pos, 1);
		push_b(a, b, 1);
		if (b->size >= 2 && b->top->index < lo + (chunk / 2))
			rotate_b(b, 1);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	pos;

	push_chunks(a, b);
	while (b->size > 0)
	{
		pos = find_pos_max(b);
		rot_to_top(b, pos, 0);
		push_a(a, b, 1);
	}
}
