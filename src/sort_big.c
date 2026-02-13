/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:58:22 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 14:58:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*stack_to_array(t_stack *a)
{
	int		*arr;
	t_node	*tmp;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		error_exit();
	tmp = a->top;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	return (arr);
}

void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	index_stack(t_stack *a)
{
	int		i;
	int		*arr;
	t_node	*tmp;

	arr = stack_to_array(a);
	sort_array(arr, a->size);
	tmp = a->top;
	while (tmp)
	{
		i = 0;
		while (i < a->size)
		{
			if (tmp->value == arr[i])
			{
				tmp->value = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	index_stack(a);
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((a->top->value >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
