/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:16:11 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/26 18:16:23 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos_chunk(t_stack *a, int low, int high)
{
	t_node	*cur;
	int		i;

	cur = a->top;
	i = 0;
	while (cur)
	{
		if (cur->index >= low && cur->index <= high)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}

int	find_pos_max(t_stack *s)
{
	t_node	*cur;
	int		i;
	int		best_i;
	int		best_idx;

	cur = s->top;
	i = 0;
	best_i = 0;
	best_idx = -2147483648;
	while (cur)
	{
		if (cur->index > best_idx)
		{
			best_idx = cur->index;
			best_i = i;
		}
		cur = cur->next;
		i++;
	}
	return (best_i);
}

void	rot_to_top(t_stack *s, int pos, int is_a)
{
	int	forward;
	int	steps;

	forward = 1;
	steps = pos;
	if (pos > s->size / 2)
	{
		forward = 0;
		steps = s->size - pos;
	}
	while (steps > 0)
	{
		if (forward && is_a)
			rotate_a(s, 1);
		else if (forward && !is_a)
			rotate_b(s, 1);
		else if (!forward && is_a)
			rev_rotate_a(s, 1);
		else
			rev_rotate_b(s, 1);
		steps--;
	}
}
