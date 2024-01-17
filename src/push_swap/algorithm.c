/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 13:30:28 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:01:28 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int rarb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n)
{
    int i;

    i = index_after_pushing_to_b(stack_b, n);
    if (i < retrieve_index(stack_a, n))
        i = retrieve_index(stack_a, n);
    return (i);
}

int rrarrb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n)
{
    int i;

    i = 0;
    if (index_after_pushing_to_b(stack_b, n))
        i = stack_size(stack_b) - index_after_pushing_to_b(stack_b, n);
    if ((i < (stack_size(stack_a) - retrieve_index(stack_a, n))) && retrieve_index(stack_a, n))
        i = stack_size(stack_a) - retrieve_index(stack_a, n);
    return (i);
}

int rrarb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n)
{
    int i;

    i = 0;
    if (retrieve_index(stack_a, n))
        i = stack_size(stack_a) - retrieve_index(stack_a, n);
    i = index_after_pushing_to_b(stack_b, n) + i;
    return (i);
}

int rarrb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n)
{
    int i;

    i = 0;
    if (index_after_pushing_to_b(stack_b, n))
        i = stack_size(stack_b) - index_after_pushing_to_b(stack_b, n);
    i = retrieve_index(stack_a, n) + i;
    return (i);
}