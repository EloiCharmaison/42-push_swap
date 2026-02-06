/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:24:43 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 19:24:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
} t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
} t_stack;

int		main(int argc, char **argv);
int 	is_valid_number(char *str);
int		ft_atoi_ps(const char *str, int *error);
void	fill_stack(int argc, char **argv, t_stack *stack);
t_node *new_node(int value);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	error_exit(void);
int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
int	get_min(t_stack *a);
int	get_position(t_stack *a, int value);
void	sort_two(t_stack *a);
void sort_three(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
char	*stack_to_array(t_stack *a);
void	sort_array(char *arr, int size);
void	index_stack(t_stack *a);
void	sort_big(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);

#endif