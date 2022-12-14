#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node *make_node(int v, node *q) {
  node *p = malloc(sizeof(node));
  p->value = v;
  p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list(node *p) {
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

/* print list to console */
void print_list(node *p) {
  if(p != NULL) {
    printf("%d--->", p->value);
    print_list(p->next);
  } else {
    printf("NULL");
  }
}

int sum_squares(node *p) {
  if(p != NULL) {
    return p->value * p->value + sum_squares(p->next);
  }
  return 0;
}

typedef int (*fn_int_to_int)(int);

node *map(node *p, fn_int_to_int f) { 
  if(p != NULL) {
    return make_node(f(p->value), map(p->next, f));
  }
  return NULL; 
}

int square(int x) { return x * x; }

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
