/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:58:43 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:01:01 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;
	int	total;

	max_bits = 0;
	while ((a->size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		total = a->size + b->size;
		j = 0;
		while (j < total)
		{
			if (((a->top->index >> i) & 1) == 0)
				push_b(a, b, 1);
			else
				rotate_a(a, 1);
			j++;
		}
		while (b->size)
			push_a(a, b, 1);
		i++;
	}
}
