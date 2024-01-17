#include <stdio.h>
#include <unistd.h>

typedef struct  node
{
    int x;
    int y;
    struct node *next;
}               node;

int main(int argc, char **argv) {
    node list;
    list.x = 10;
    list.next->x = 15;
    printf("Primeiro elemento: %i\n", list.x);
    printf("Segundo elemento: %i\n", list.next->y);
    return (0);
}