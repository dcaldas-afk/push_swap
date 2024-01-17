/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:26:31 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 18:13:01 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
#include <string.h>

typedef struct	s_stack
{
	int	n;
	int	index;
	struct  s_stack  *next;
	struct  s_stack *previous;
}				t_stack;

// Funções auxiliares
void    ft_putstr(char *str);
void    free_stack(t_stack **stack_x);
void    print_stack(t_stack *stack_x);
void    change_last_value(t_stack **stack_x, t_stack *tmp, void *value);
void    error_exit();
int		try_stack(t_stack   *stack);
int		stack_size(t_stack *stack_x);
int     return_largest(t_stack *stack_x);
int     return_smallest(t_stack *stack_x);
t_stack	*last_element(t_stack *list);

// Funções da Libft
void	ft_freestr(char *str);
void	ft_strcpy(char *dst, const char *src);
int		ft_atoi(const char *nptr);
char	*ft_mallocnstr(const char *s, char n, int *i);
char	**ft_split(char const *str, char c);
size_t	ft_wordcounter(const char *str, char c);

// Operações
void    sa(t_stack **stack_a, int len);
void    sb(t_stack **stack_b, int len);
void    ss(t_stack **stack_a, t_stack **stack_b, int len);
void    pa(t_stack **stack_a, t_stack **stack_b, int len);
void    pb(t_stack **stack_a, t_stack **stack_b, int len);
void    ra(t_stack **stack_a, int len);
void    rb(t_stack **stack_b, int len);
void    rr(t_stack **stack_a, t_stack **stack_b, int len);
void	rra(t_stack **stack_a, int len);
void	rrb(t_stack **stack_b, int len);
void    rrr(t_stack **stack_a, t_stack **stack_b, int len);

// Checagem do vetor de argumentos e pilhas
int is_sign(int c);
int is_digit(int c);
int is_space(int c);
int	is_alphanumerical(int c);
bool    argv_check(char **argv, int i, int j);
bool    is_argv_alphanum(char **argv);
bool    is_argv_valid(char **argv);
bool    is_duplicate(t_stack *stack_x);
bool    is_sorted(t_stack *stack_x);

// Manipulação de listas para além das operações obrigatórias
void    free_lst(char **lst);
int retrieve_index(t_stack *stack_x, int value);
int index_after_pushing_to_a(t_stack *stack_a, int n);
int index_after_pushing_to_b(t_stack *stack_b, int n);
t_stack	*create_stack(int arg);


// Parser (que ódio disso aqui)
//void    parse_quotes(t_stack **stack, char **argv);
void    add_node(t_stack **stack, t_stack *new);
void    list_args(t_stack **stack, char **argv);
t_stack	*parse_quoted_argv(char **argv);
t_stack *parser(int argc, char **argv);

// funções do algoritmo
int rarb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n);
int rrarrb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n);
int rrarb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n);
int rarrb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n);
int rarb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n);
int rrarrb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n);
int rrarb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n);
int rarrb_quantity_b(t_stack *stack_a, t_stack *stack_b, int n);
int	apply_rarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int	apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int	apply_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int	apply_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int	rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack **stack_a);
void    reduce_b(t_stack **stack_a, t_stack **stack_b);
t_stack *sort_b(t_stack **stack_a);
t_stack **sort_a(t_stack **stack_a, t_stack **stack_b);
void    solve(t_stack **stack_a);

#endif