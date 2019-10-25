#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//#include "header.h"

struct node { int i; struct node *next; };

void print_list(struct node *x) {
    if (x == NULL) {
      printf("[ ]");
      return;
    }
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
    struct node *temp = malloc(sizeof(struct node));
    temp -> i = y;
    temp -> next = x;
    return temp;
}

struct node * free_list(struct node *x) {
    struct node *temp = x;
    if (temp == NULL) {
      free(x);
      return;
    };
    while(temp -> next != NULL) {
      printf("Freeing node: %d\n", temp-> i);
      x = temp;
      temp = temp -> next;
      free(x);
    }
    return temp;
}

int main() {
    struct node *run = malloc (sizeof(struct node));
    printf("Printing empty list:\n");
    run->i = 0;
    run->next =  NULL;
    print_list(run);
    printf("Adding #s 0-9 t list:\n");
    for (int i = 0; i < 10; i++) {
      run = insert_front(run, i);
    }
    print_list(run);
    printf("Freeing list:\n");
    run = free_list(run);
    printf("Printing list:\n");
    print_list(run);

}
