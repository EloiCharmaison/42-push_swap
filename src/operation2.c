/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:38:35 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 01:38:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*first;
	t_node	*last;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	a->top = first->next;
	last = a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*first;
	t_node	*last;

	if (!b || b->size < 2)
		return ;
	first = pop_node(b);
	last = b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	b->size++;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
