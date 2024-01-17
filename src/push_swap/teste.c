# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_stack
{
	int	*n;
	int	*index;
	struct  s_stack  *next;
	struct  s_stack *previous;
}				t_stack;

int	try_stack(t_stack *stack)
{
	if (!stack || !(stack->next))
		return (0);
	return (1);
}

t_stack	*last_element(t_stack *stack_x)
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

int retrieve_index(t_stack *stack_x, int value)
{
    int i = 0;
    while (stack_x && *(stack_x->n) != value)
    {
        i++;
        stack_x = stack_x->next;
    }
    if (stack_x)
        *(stack_x->index) = i;
    return i;
}

int	return_largest(t_stack *stack_x)
{
	int	max;

	max = *(stack_x->n);
	while (stack_x)
	{
		if (*(stack_x->n) > max)
			max = *(stack_x->n);
		stack_x = stack_x->next;
	}
	return (max);
}

int	stack_size(t_stack *stack_x)
{
	int	i;

	i = 0;
	while (stack_x)
	{
		i++;
		stack_x = stack_x->next;
	}
	return (i);
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

void rra(t_stack **stack_a, int len)
{
    t_stack *tmp; 
    
    tmp = *stack_a;
    change_last_value(stack_a, tmp, NULL);
    if (len == 0)
        write(1, "rra\n", 4);
}

void sort(t_stack **stack_a, t_stack **stack_b)
{
    int max;
    int max_index;

    while (*stack_a)
    {
        max = return_largest(*stack_a);
        max_index = retrieve_index(*stack_a, max);

        if (max_index < (stack_size(*stack_a) / 2))
        {
            while (*((*stack_a)->n )!= max)
                ra(stack_a, 0);
        }
        else
        {
            while (*((*stack_a)->n )!= max)
                rra(stack_a, 0);
        }

        pa(stack_a, stack_b, 0);
    }

    while (*stack_b)
    {
        pb(stack_a, stack_b, 0);
        ra(stack_a, 0);
    }
}

int main()
{
    // Exemplo de uso das funções e estruturas

    // Criação de pilhas
    t_stack *stack_a = malloc(sizeof(t_stack));
    t_stack *stack_b = NULL;  // Inicializando stack_b como uma pilha vazia

    // Inicialização dos elementos das pilhas (substitua com seus valores)
    int values_a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size_a = sizeof(values_a) / sizeof(values_a[0]);

    for (int i = 0; i < size_a; i++)
    {
        t_stack *new_element = malloc(sizeof(t_stack));
        new_element->n = malloc(sizeof(int));
        *(new_element->n) = values_a[i];
        new_element->index = NULL;
        new_element->next = NULL;
        new_element->previous = NULL;

        // Adiciona o novo elemento à pilha
        if (stack_a)
        {
            new_element->next = stack_a;
            stack_a->previous = new_element;
        }
        stack_a = new_element;
    }

    // Testa a função sort
        sort(&stack_a, &stack_b);

    // Imprime as pilhas após a ordenação
    printf("Stack A (sorted): ");
    t_stack *current_a = stack_a;
    while (current_a)
    {
        printf("%d ", *(current_a->n));
        t_stack *temp = current_a;
        current_a = current_a->next;
        free(temp->n);
        free(temp);
    }
    printf("\n");

    printf("Stack B: ");
    t_stack *current_b = stack_b;
    while (current_b)
    {
        printf("%d ", *(current_b->n));
        t_stack *temp = current_b;
        current_b = current_b->next;
        free(temp->n);
        free(temp);
    }
    printf("\n");

    return 0;
}