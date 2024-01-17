/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:25:14 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:03:43 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void    sa(t_stack **stack_a, int len)
{
    t_stack *tmp;

    if (try_stack(*stack_a) == 0)
        return ;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = (*stack_a)->next;
    (*stack_a)->next = tmp;
    if (len == 0)
        write(1,"sa\n", 3);
}

void    sb(t_stack **stack_b, int len)
{
    t_stack *tmp;

    if (try_stack(*stack_b) == 0)
        return ;
    tmp = *stack_b;
    *stack_b = (*stack_b);
    *stack_b = (*stack_b)->next;
    tmp->next = (*stack_b)->next;
    (*stack_b)->next = tmp;
    if (len == 0)
        write(1,"sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b, int len)
{
    if (try_stack(*stack_a) == 0 || try_stack(*stack_b) == 0)
        return ;
    sa(stack_a, len);
    sb(stack_b, len);
    if (len == 0)
        write(1, "ss\n", 3);
}

void    pa(t_stack **stack_a, t_stack **stack_b, int len)
{
    t_stack *tmp;

    if (try_stack(*stack_b) == 0)
        return ;
    tmp = *stack_a;
    *stack_a = *stack_b;
    *stack_b = (*stack_b)->next;
    (*stack_a)->next = tmp;
    if (len == 0)
        write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b, int len)
{
    t_stack *tmp;

    if (try_stack(*stack_a) == 0)
        return ;
    tmp = *stack_b;
    *stack_b = *stack_a;
    *stack_a = (*stack_a)->next;
    (*stack_b)->next = tmp;
    if (len == 0)
        write(1, "pb\n", 3);
}

void    ra(t_stack **stack_a, int len)
{
    t_stack *tmp;

    tmp = *stack_a;
    *stack_a = last_element(*stack_a);
    (*stack_a)->next = tmp;
    *stack_a = tmp->next;
    tmp->next = NULL;
    if (len == 0)
        write(1, "ra\n", 3);
}

void    rb(t_stack **stack_b, int len)
{
    t_stack *tmp;

    tmp = *stack_b;
    *stack_b = last_element(*stack_b);
    (*stack_b)->next = tmp;
    *stack_b = tmp->next;
    tmp->next = NULL;
    if (len == 0)
        write(1, "rb\n", 3);
}

void    rr(t_stack **stack_a, t_stack **stack_b, int len)
{
    ra(stack_a, len);
    rb(stack_b, len);
    if (len == 0)
        write(1, "rr\n", 3);
}