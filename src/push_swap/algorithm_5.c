/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:44:55 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 17:42:09 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

// Rodar o algoritmo até ficar só 3 números em B
void    reduce_b(t_stack **stack_a, t_stack **stack_b)
{
    int i;
    t_stack *tmp;

    while (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
    {
        tmp = *stack_a;
        i = rotate_type_ab(*stack_a, *stack_b);
        while (i >= 0)
        {
            if (i == rarb_quantity_b(*stack_a, *stack_b, tmp->n))
                i = apply_rarb(stack_a, stack_b, tmp->n, 'a');
            else if (i == rarrb_quantity_b(*stack_a, *stack_b, tmp->n))
                i = apply_rarrb(stack_a, stack_b, tmp->n, 'a');
            else if (i == rrarb_quantity_b(*stack_a, *stack_b, tmp->n))
                i = apply_rrarb(stack_a, stack_b, tmp->n, 'a');
            else if (rrarrb_quantity_b(*stack_a, *stack_b, tmp->n))
                i = apply_rrarrb(stack_a, stack_b, tmp->n, 'a');
            else
                tmp = tmp->next;
        }
    }
}

// Passa tudo que está em A para B, até sobrarem apenas 3 elementos
t_stack *sort_b(t_stack **stack_a)
{
    t_stack *stack_b;

    stack_b = NULL;
    if (!is_sorted(*stack_a) && stack_size(*stack_a) > 3)
        pb(stack_a, &stack_b, 0);
    if (!is_sorted(*stack_a) && stack_size(*stack_a) > 3)
        pb(stack_a, &stack_b, 0);
    if (!is_sorted(*stack_a) && stack_size(*stack_a) > 3)
        reduce_b(stack_a, &stack_b);
    if (!is_sorted(*stack_a))
        sort_three(stack_a);
    return (stack_b);
}

// Passa tudo de B para A, até que B fique vazio
t_stack **sort_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    int i;

    while (*stack_b)
    {
        tmp = *stack_b;
        i = rotate_type_ba(*stack_a, *stack_b);
        while (i >= 0)
        {
            if (i == rrarb_quantity_a(*stack_a, *stack_b, tmp->n))
                apply_rrarb(stack_a, stack_b, tmp->n, 'b');
            else if (i == rarb_quantity_a(*stack_a, *stack_b, tmp->n))
                apply_rarb(stack_a, stack_b, tmp->n, 'b');
            else if (i == rarrb_quantity_a(*stack_a, *stack_b, tmp->n))
                apply_rarrb(stack_a, stack_b, tmp->n, 'b');
            else if (i == rrarrb_quantity_a(*stack_a, *stack_b, tmp->n))
                apply_rrarrb(stack_a, stack_b, tmp->n, 'b');
            else
                tmp = tmp->next;
        }
    }
    return (stack_a);
}

void    solve(t_stack **stack_a)
{
    t_stack *stack_b;
    int i;

    stack_b = NULL;
    if (stack_size(*stack_a) == 2)
    {
        sa(stack_a, 0);
        return ;       
    }
    stack_b = sort_b(stack_a);
    stack_a = sort_a(stack_a, &stack_b);
    i = retrieve_index(*stack_a, return_smallest(*stack_a));
    if (i >= stack_size(*stack_a)/2)
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