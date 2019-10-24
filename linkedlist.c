#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "header.h"

struct node { int i; struct node *next; };

void print_list(struct node *x) {
    if (x == NULL) printf("[ ]");
    printf("[");
    struct node *temp = x -> next;
    if (temp == NULL) printf("");
    else {
      printf("%d ", x->i);
      while(temp->next != NULL) {
          printf("%d ", temp->i);
          temp = temp -> next;
        }
      }
    printf("]\n");
}

struct node * insert_front(struct node *x, int y) {

}
int main() {
    struct node *run = malloc (sizeof(struct node));
    printf("Printing empty list:\n");
    run->i = 0;
    run->next =  NULL;
    print_list(run);
    printf("Adding #s 0-9 t list:\n");
    free(run);
}
