/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:58:53 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/21 13:11:48 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

t_node	*node_new(int value)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->prev = NULL;
	n->next = NULL;
	return (n);
}

void	push_top(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	n->prev = NULL;
	n->next = s->top;
	if (s->top)
		s->top->prev = n;
	else
		s->bottom = n;
	s->top = n;
	s->size++;
}

t_node	*pop_top(t_stack *s)
{
	t_node	*n;

	if (s->size == 0)
		return (NULL);
	n = s->top;
	s->top = n->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	n->next = NULL;
	n->prev = NULL;
	s->size--;
	return (n);
}

void	push_bottom(t_stack *s, t_node *n)
{
	if (!n)
		return ;
	n->next = NULL;
	n->prev = s->bottom;
	if (s->bottom)
		s->bottom->next = n;
	else
		s->top = n;
	s->bottom = n;
	s->size++;
}
