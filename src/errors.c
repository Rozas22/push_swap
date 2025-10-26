/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:23:34 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/26 18:19:25 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	ft_putstr_fd("Error\n", 2);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}
