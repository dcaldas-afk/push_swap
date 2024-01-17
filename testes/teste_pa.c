#include "push_swap.h"

void    print_stack(t_stack *stack_x)
{
    while (stack_x)
    {
        printf("%d ", *(stack_x->n));
        stack_x = stack_x->next;
    }
    printf("\n");
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

int main(int argc, char **argv) {
    
    t_stack *a = (t_stack *)malloc(sizeof(t_stack));
    t_stack *b = (t_stack *)malloc(sizeof(t_stack));
    a->n = (int *)malloc(sizeof(int));
    a->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->n = (int *)malloc(sizeof(int));
    a->next->next = (t_stack *)malloc(sizeof(t_stack));
    a->next->next->n = (int *)malloc(sizeof(int));
    b->n = (int *)malloc(sizeof(int));
    b->next = (t_stack *)malloc(sizeof(t_stack));
    b->next->n = (int *)malloc(sizeof(int));

    *(a->n) = 2;
    *(a->next->n) = 3;
    *(a->next->next->n) = 7;
    *(b->n) = 4;
    *(b->next->n) = 5; 

    printf("Antes:\n");
    print_stack(a);
    print_stack(b);
    pa(&a,&b,0);
    printf("Depois:\n");
    print_stack(a);
    print_stack(b);
    // Liberar a memória alocada antes de encerrar o programa
    free_stack(&a);
    free_stack(&b);

    return 0;
}