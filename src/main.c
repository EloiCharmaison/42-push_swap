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
	t_stack a;
	t_stack b;
	
	if (argc < 2)
		return (0);
	
	a.top = NULL;
	a.size = 0;
	b.top = NULL;
	b.size = 0;
	
	fill_stack(argc, argv, &a);

	if (!is_sorted(&a))
	{
		if (a.size <= 5)
			sort_small(&a, &b);
		else
			sort_big(&a, &b);
	}
}
