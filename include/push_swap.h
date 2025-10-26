/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:59:25 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/26 18:19:45 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

int		read_args(int argc, char **argv, t_stack *a);
void	stack_init(t_stack *s);
t_node	*node_new(int value);
void	push_top(t_stack *s, t_node *n);
t_node	*pop_top(t_stack *s);
void	push_bottom(t_stack *s, t_node *n);
void	free_stack(t_stack *s);
void	swap_a(t_stack *a, int print);
void	swap_b(t_stack *b, int print);
void	swap_ab(t_stack *a, t_stack *b, int print);
void	push_a(t_stack *a, t_stack *b, int print);
void	push_b(t_stack *a, t_stack *b, int print);
void	rotate_a(t_stack *a, int print);
void	rotate_b(t_stack *b, int print);
void	rotate_ab(t_stack *a, t_stack *b, int print);
void	rev_rotate_a(t_stack *a, int print);
void	rev_rotate_b(t_stack *b, int print);
void	rev_rotate_ab(t_stack *a, t_stack *b, int print);
void	sort_small(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);
int		is_sorted(t_stack *a);
long	str_to_long(const char *s, int *ok);
int		has_duplicate(int *arr, int n);
void	assign_indexes(t_stack *a);
void	print_str(const char *s);
void	error_exit(t_stack *a, t_stack *b);
int		find_pos_chunk(t_stack *a, int low, int high);
int		find_pos_max(t_stack *s);
void	rot_to_top(t_stack *s, int pos, int is_a);

#endif
