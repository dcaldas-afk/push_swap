/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:11:47 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/29 21:35:33 by dcaldas-         ###   ########.fr       */
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
	free_stack(&stack);
	return (0);
}
