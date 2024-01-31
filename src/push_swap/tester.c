/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:22:37 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/29 21:35:48 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parser(argc, argv);
	if (!stack || is_duplicate(stack))
	{
		free_stack(&stack);
		error_exit();
	}
	if (is_sorted(stack))
		exit(1);
	solve(&stack);
	print_stack(stack);
	free_stack(&stack);
	return (0);
}
