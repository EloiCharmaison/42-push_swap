/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:46:08 by marvin            #+#    #+#             */
/*   Updated: 2026/02/05 22:46:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		error_exit(&a);
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	if (!arg_check(argc, argv, &a))
		return (0);
	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}

void	print_stack(t_stack *a)
{
	t_node *current;

	current = a->top;
	while (current != NULL)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
}

int	arg_check(int argc, char **argv, t_stack *a)
{
	char	**args;
	int		len;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
			free_exit(args, NULL);
		len = 0;
		while (args[len])
			len++;
		if (len == 1)
			free_exit(args, a);
		fill_stack(len, args, a);
		free_tab(args);
	}
	else if (argc > 2)
		fill_stack(argc - 1, argv + 1, a);
	else
		error_exit(a);
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_exit(char **tab, t_stack *a)
{
	free_tab(tab);
	error_exit(a);
}