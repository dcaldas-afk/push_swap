/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 03:11:47 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:02:46 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack;

    stack = parser(argc, argv);
    if (!stack || is_duplicate(stack)) //checa se há números duplicados
    {
        free_stack(&stack); // liberar memória pra não dar merda no valgrind depois, OK
        error_exit(); // mensagem de erro, OK
    }
    solve(&stack);
    free_stack(&stack); // tem que liberar, né, OK
    return (0);
}