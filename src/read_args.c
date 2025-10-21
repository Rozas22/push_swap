/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikrozas <ikrozas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:56:40 by ikrozas           #+#    #+#             */
/*   Updated: 2025/10/20 21:06:27 by ikrozas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* libera un split de ft_split */
static void	free_split(char **sp)
{
	int	i;

	i = 0;
	while (sp && sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

/* convierte y mete un número en arr[k] */
static int	add_number(const char *s, int *arr, int *k)
{
	int		ok;
	long	val;

	val = str_to_long(s, &ok);
	if (!ok || val < INT_MIN || val > INT_MAX)
		return (0);
	arr[*k] = (int)val;
	(*k)++;
	return (1);
}

/* cuenta cuántos tokens hay en todos los argv (soporta "1 2 3") */
static int	count_tokens(int argc, char **argv)
{
	int		total;
	int		i;
	int		j;
	char	**sp;

	total = 0;
	i = 1;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp)
			return (-1);
		j = 0;
		while (sp[j])
		{
			total++;
			free(sp[j]);
			j++;
		}
		free(sp);
		i++;
	}
	return (total);
}

/* rellena arr con todos los números (valida rango y formato) */
static int	fill_array(int argc, char **argv, int *arr)
{
	int		i;
	int		k;
	int		j;
	char	**sp;

	i = 1;
	k = 0;
	while (i < argc)
	{
		sp = ft_split(argv[i], ' ');
		if (!sp)
			return (0);
		j = 0;
		while (sp[j])
		{
			if (!add_number(sp[j], arr, &k))
				return (free_split(sp), 0);
			j++;
		}
		free_split(sp);
		i++;
	}
	return (1);
}

/* crea stack A desde argv, comprueba duplicados */
int	read_args(int argc, char **argv, t_stack *a)
{
	int		total;
	int		*arr;
	int		i;

	total = count_tokens(argc, argv);
	if (total <= 0)
		return (0);
	arr = (int *)ft_calloc(total, sizeof(int));
	if (!arr)
		return (0);
	if (!fill_array(argc, argv, arr))
		return (free(arr), 0);
	if (has_duplicate(arr, total))
		return (free(arr), 0);
	i = total - 1;
	while (i >= 0)
	{
		push_top(a, node_new(arr[i]));
		i--;
	}
	free(arr);
	return (1);
}
