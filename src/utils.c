/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:57:56 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/21 13:12:13 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_str(const char *s)
{
	write(1, s, ft_strlen(s));
}

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	if (a->size < 2)
		return (1);
	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

long	str_to_long(const char *s, int *ok)
{
	long	sign;
	long	res;

	*ok = 0;
	sign = 1;
	res = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		sign = 1 - 2 * (*s++ == '-');
	if (!ft_isdigit((unsigned char)*s))
		return (0);
	while (ft_isdigit((unsigned char)*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s)
		return (0);
	*ok = 1;
	return (res * sign);
}

int	has_duplicate(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	assign_indexes(t_stack *a)
{
	int		n;
	t_node	*i;
	t_node	*j;
	int		rank;

	(void)n;
	i = a->top;
	while (i)
	{
		rank = 0;
		j = a->top;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}
