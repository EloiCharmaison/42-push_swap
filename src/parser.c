/* ************************************************************************** */

/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:32:53 by marvin            #+#    #+#             */
/*   Updated: 2026/02/04 23:32:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Vérifie si la string est un nombre valide
*/
int is_valid_number(char *str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
	return (1);
}

int	ft_atoi_ps(const char *str, int *error)
{
	long result;
	int sign;

	result = 0;
	sign = 1;
	*error = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		result = result * 10 + (*str - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(result * sign));
}

void	fill_stack(int argc, char **argv, t_stack *stack)
{
	int		i;
	int		value;
	int		error;
	t_node	*node;

	i = argc - 1;
	while (i > 0)
	{
		if (!is_valid_number(argv[i]))
			error_exit();
		value = ft_atoi_ps(argv[i], &error);
		if (error)
			error_exit();
		node = new_node(value);
		if (!node)
			error_exit();
		push_node(stack, node);
		i--;
	}
}
