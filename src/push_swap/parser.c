/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:55:45 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/29 21:02:23 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	add_node(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (stack)
	{
		if (*stack == NULL)
			*stack = new;
		else
		{
			tmp = last_element(*(stack));
			tmp->next = new;
		}
	}
}

t_stack	*parse_quoted_argv(char **argv)
{
	int		i;
	int		j;
	char	**tmp;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi(tmp[i]);
		add_node(&stack, create_stack(j));
		i++;
	}
	free_str(tmp);
	free(tmp);
	return (stack);
}

t_stack	*parser(int argc, char **argv)
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
