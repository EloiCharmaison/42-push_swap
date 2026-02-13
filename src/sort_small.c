/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:11:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 13:11:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_stack *a, int value)
{
	t_node	*tmp;
	int		pos;

	tmp = a->top;
	pos = 0;
	while (tmp)
	{
		if (tmp->value == value)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;
	int	rotation;

	min = get_min(a);
	pos = get_position(a, min);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		rotation = a->size - pos;
		while (rotation-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
	{
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else if (a->size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
