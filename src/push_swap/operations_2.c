/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:41:27 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:03:36 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void rra(t_stack **stack_a, int len)
{
    t_stack *tmp; 
    
    tmp = *stack_a;
    change_last_value(stack_a, tmp, NULL);
    if (len == 0)
        write(1, "rra\n", 4);
}

void rrb(t_stack **stack_b, int len)
{
    t_stack *tmp; 
    
    tmp = *stack_b;
    change_last_value(stack_b, tmp, NULL);
    if (len == 0)
        write(1, "rba\n", 4);
}

void    rrr(t_stack **stack_a, t_stack **stack_b, int len)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    if (len == 0)
        write(1, "rrr\n", 4);
}