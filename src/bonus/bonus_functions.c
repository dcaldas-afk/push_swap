/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:01:40 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:45:01 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"
#include "../../lib/checker.h"

t_stack	*checker_parser(int argc, char **argv)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	if (argc < 2)
		exit(1);
	if (argc == 2)
		stack = parse_quoted_argv(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi(argv[i]);
			add_node(&stack, create_stack(j));
			i++;
		}
	}
	return (stack);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b)
{
	*stack_b = sort_b(stack_a);
	stack_a = sort_a(stack_a, stack_b);
	if (!try_stack(*stack_b))
		ko_exit();
}

void	checker(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (stack_size(*stack_a) == 2)
	{
		sa(stack_a, 0);
		return ;
	}
	sort_all(stack_a, &stack_b);
	i = retrieve_index(*stack_a, return_smallest(*stack_a));
	if (i >= stack_size(*stack_a) / 2)
	{
		while ((*stack_a)->n != return_smallest(*stack_a))
			rra(stack_a, 0);
	}
	else
	{
		while ((*stack_a)->n != return_smallest(*stack_a))
			ra(stack_a, 0);
	}
}
