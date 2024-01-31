/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:25:22 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/27 07:02:14 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

bool	is_argv_alphanum(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (is_alphanumerical(argv[i][j]))
				j++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

bool	is_argv_valid(char **argv)
{
	bool	ac;
	bool	dc;

	ac = is_argv_alphanum(argv);
	dc = argv_check(argv, 1, 0);
	if (ac == true || dc == true)
		return (true);
	else
	{
		error_exit();
		return (false);
	}
}

int	is_duplicate(t_stack *stack_x)
{
	t_stack	*tmp;

	while (stack_x)
	{
		tmp = stack_x->next;
		while (tmp)
		{
			if (stack_x->n == tmp->n)
				return (1);
			tmp = tmp->next;
		}
		stack_x = stack_x->next;
	}
	return (0);
}

bool	is_sorted(t_stack *stack_x)
{
	int	i;

	i = stack_x->n;
	while (stack_x)
	{
		if (i > stack_x->n)
			return (false);
		i = stack_x->n;
		stack_x = stack_x->next;
	}
	return (true);
}
