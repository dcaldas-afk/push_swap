#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_stack
{
	int *n;
	int *index;
	struct  s_stack  *next;
	struct  s_stack *previous;
}				t_stack;

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

int try_stack(t_stack   *stack)
{
    if (!stack || !(stack->next))
        return (0);
    return (1);
}

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

int     return_largest(t_stack *stack_x)
{
    int max;

    max = *(stack_x->n);
    while (stack_x)
    {
        if (*(stack_x->n) > max)
            max = *(stack_x->n);
        stack_x = stack_x->next;
    }
    return (max);
}

int     return_smallest(t_stack *stack_x)
{
    int min;

    min = *(stack_x->n);
    while (stack_x)
    {
        if (*(stack_x->n) < min)
            min = *(stack_x->n);
        stack_x = stack_x->next;
    }
    return (min);
}

int main(int argc, char **argv)
{
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    a->n = (int *)malloc(sizeof(int));
    a->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->n = (int *)malloc(sizeof(int));
    a->next->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->next->n = (int *)malloc(sizeof(int));

    int max, min;

    *(a->n) = 2;
    *(a->next->n) = 4;
    *(a->next->next->n) = 5;

    printf("Antes:\n");
    printf("%i\n", *(a->n));
    printf("%i\n", *(a->next->n));
    printf("%i\n", *(a->next->next->n));
    max = return_largest(a);
    min = return_smallest(a);
    printf("Max: %i\n", max);
    printf("Min: %i\n", min);
    printf("Depois:\n");
    printf("%i\n", *(a->n));
    printf("%i\n", *(a->next->n));
    printf("%i\n", *(a->next->next->n));
    // Liberar a memória alocada antes de encerrar o programa
    free_stack(&a);

    return 0;
}
