/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:55:45 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 18:03:52 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void    add_node(t_stack **stack, t_stack *new)
{
    if (!stack)
        return ;
    if (!*stack)
        *stack = new;
    (last_element(*stack))->next = new;
}

void    list_args(t_stack **stack, char **argv)
{
    int i;

    i = 0;
    while (argv[i] != NULL)
    {
        add_node(stack, create_stack(ft_atoi(argv[i])));    // função para poder criar um nó em cima do índice
        i++;                                                // itera para o próximo índice
    }
    
}

t_stack *parse_quoted_argv(char **argv)
{
    int i;
    char    **tmp;
    t_stack *stack;
    
    i = 0;
    stack = NULL;
    tmp = ft_split(argv[i], 32);                             // Certificar que split funciona
    list_args(&stack, tmp);
    free_lst(tmp);
    free(tmp);
    return (stack);
}

t_stack *parser(int argc, char **argv)
{
    t_stack *stack;

    if (argc < 2)
        error_exit();
    else if (argc == 2)
        parse_quoted_argv(argv);                                 // função para lidar com aspas
    else                                                // para argc > 2
        list_args(&stack, argv);                        // função para listar argumentos
    return (stack);
}