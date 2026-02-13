/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:16:46 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 01:16:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = pop_node(a);
	second = pop_node(a);
	push_node(a, second);
	push_node(a, first);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b || b->size < 2)
		return ;
	first = pop_node(b);
	second = pop_node(b);
	push_node(b, first);
	push_node(b, second);
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || b->size == 0)
		return ;
	node = pop_node(b);
	push_node(a, node);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0)
		return ;
	node = pop_node(a);
	push_node(b, node);
	ft_printf("pb\n");
}
