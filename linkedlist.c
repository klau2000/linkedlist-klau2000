#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

void print_list(struct node *x) {
    if (x == NULL) {
      printf("[ ]\n");
      return;
    }
    printf("[ ");
    struct node *temp = x -> next;
    if (temp == NULL) printf("");
    else {
      printf("%d ", x->i);
      while(temp != NULL) {
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
    while(temp != NULL) {
      printf("Freeing node: %d\n", temp-> i);
      x = temp;
      temp = temp -> next;
      free(x);
      x = NULL;
    }
    free(temp);
    return x;
}

struct node * remove_node(struct node *front, int data){
    struct node *temp = front->next;
    struct node *prev = front;
    if (front ->i == data) {
      front = NULL;
      free(front);
      return temp;
    };
    while (temp != NULL) {
      if(temp -> i == data){
        prev -> next = temp -> next;
        free(temp);
        temp = NULL;
        return front;
      }
      prev = temp;
      temp = temp -> next;
    }
    return front;
}
