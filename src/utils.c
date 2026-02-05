/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:41:58 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 11:41:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

int	is_sorted(t_stack *stack)
{
	t_node *current;

	if (!stack || stack->size < 2)
		return (1);
	current	 = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_size(t_stack *stack)
{
	if (!satck)
		return (0);
	return ( stack->size);
}
