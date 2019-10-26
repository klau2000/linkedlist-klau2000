#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main() {
    struct node *run = malloc (sizeof(struct node));
    printf("Printing empty list:\n");
    run = NULL;
    print_list(run);

    printf("Adding #s 0-9 t list:\n");
    for (int i = 0; i < 10; i++) {
      run = insert_front(run, i);
    }
    print_list(run);

    printf("Removing 9:\n");
    run = remove_node(run, 9);
    print_list(run);
    printf("Removing 5:\n");
    run = remove_node(run, 5);
    print_list(run);
    printf("Removing 0:\n");
    run = remove_node(run, 0);
    print_list(run);
    printf("Removing -1:\n");
    run = remove_node(run, -1);
    print_list(run);

    printf("Freeing list:\n");
    run = free_list(run);
    printf("Printing list:\n");
    print_list(run);

}
