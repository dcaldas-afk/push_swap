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
        return (NULL);
    while (stack_x->next)
        stack_x = stack_x->next;
    return (stack_x);
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

void rrX_algorithm(t_stack **stack_x, t_stack *copy) 
{
    int i;

    i = 0;
    while ((*stack_x)->next)
    {
        i++;
        (*stack_x) = (*stack_x)->next;
    }
    (*stack_x)->next = copy;
    while (i > 1)
    {
        i--;
        copy = copy->next;
    }
    copy->next = NULL;
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

void    ra(t_stack **stack_a, int len)
{
    t_stack *tmp;

    tmp = *stack_a;
    *stack_a = last_element(*stack_a);
    (*stack_a)->next = tmp;
    *stack_a = tmp->next;
    if (len == 0)
        write(1, "ra\n", 3);
}

void rra(t_stack **stack_a, int len)
{
    t_stack *tmp; 
    
    tmp = *stack_a;
    change_last_value(stack_a, tmp, NULL);
    if (len == 0)
        write(1, "rra\n", 3);
}

int main(int argc, char **argv) {
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    a->n = (int *)malloc(sizeof(int));
    a->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->n = (int *)malloc(sizeof(int));
    a->next->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->next->n = (int *)malloc(sizeof(int));
    a->next->next->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->next->next->n = (int *)malloc(sizeof(int));

    (*a->n) = 1;
    (*a->next->n) = 2;
    (*a->next->next->n) = 3;
    (*a->next->next->next->n) = 4;

    printf("Antes:\n");
    print_stack(a);
    rra(&a, 0);
    printf("Depois:\n");
    print_stack(a);

    // Liberar a memória alocada antes de encerrar o programa
    free_stack(&a);

    return 0;
}