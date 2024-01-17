/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:31:03 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/12/19 03:41:30 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int try_stack(t_stack   *stack)
{
    if (!stack || !(stack->next))
        return (0);
    return (1);
}

void    free_stack(t_stack **stack_x)
{
    t_stack *tmp;

    if (!stack_x)
        return ;
    while (*stack_x)
    {
        tmp = (*stack_x)->next;
        (*stack_x)->n = 0;
        free(*stack_x);
        *stack_x = tmp;
    }
}

t_stack *last_element(t_stack *stack_x)
{
    if (!stack_x)
        return NULL;
    while (stack_x->next)
        stack_x = stack_x->next;
    return (stack_x);
}

void    print_stack(t_stack *stack_x)
{
    while (stack_x)
    {
        printf("%d ", *(stack_x->n));
        stack_x = stack_x->next;
    }
    printf("\n");
}

void    change_last_value(t_stack **stack_x, t_stack *tmp, void *value)
{
    int i;

    i = 0;
    tmp = *stack_x;
    while ((*stack_x)->next)
    {
        i++;
        *stack_x = (*stack_x)->next;
    }
    (*stack_x)->next = tmp;
    while (i > 1)
    {
        i--;
        tmp = tmp->next;
    }
    tmp->next = value;
}