/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:01:20 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/30 16:45:40 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"
#include "../../lib/checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = checker_parser(argc, argv);
	if (!stack || is_duplicate(stack))
	{
		free_stack(&stack);
		error_exit();
	}
	if (is_sorted(stack))
		ko_exit();
	checker(&stack);
	if (is_sorted(stack))
	{
		free_stack(&stack);
		ok_exit();
	}
	return (0);
}
