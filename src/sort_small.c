/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:58:48 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/21 13:08:24 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pos_min(t_stack *a)
{
	int		pos;
	int		best;
	int		i;
	t_node	*cur;

	cur = a->top;
	best = cur->index;
	pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->index < best)
		{
			best = cur->index;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

static void	sort_three(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->bottom->index;
	if (x < y && y < z)
		return ;
	if (x > y && x < z)
		swap_a(a, 1);
	else if (x > y && y > z)
	{
		swap_a(a, 1);
		rev_rotate_a(a, 1);
	}
	else if (x > y && y < z && x > z)
		rotate_a(a, 1);
	else if (x < y && x < z && y > z)
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
	else if (x < y && x > z)
		rev_rotate_a(a, 1);
}

static void	bring_min_to_top(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
		while (pos--)
			rotate_a(a, 1);
	else
	{
		pos = a->size - pos;
		while (pos--)
			rev_rotate_a(a, 1);
	}
}

static void	push_mins_to_b(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
	{
		pos = pos_min(a);
		bring_min_to_top(a, pos);
		push_b(a, b, 1);
	}
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			swap_a(a, 1);
		return ;
	}
	if (a->size == 3)
		return (sort_three(a));
	push_mins_to_b(a, b);
	sort_three(a);
	while (b->size)
		push_a(a, b, 1);
}
