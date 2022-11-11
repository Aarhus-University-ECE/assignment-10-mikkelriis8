#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "btree.h"


// Print tree
void print_tree(struct tree_node *p, int depth) {
  for(int i = 0; i < depth; i++) {
    printf("   ");
  }
  printf(">|");
  if(p == NULL) {
    printf("NULL\n");
  } else {
    printf("[%d]\n", p->item);
  }
  if(p->left) {
    print_tree(p->left, depth + 1);
  }
  if(p->right) {
    print_tree(p->right, depth + 1);
  }
}







// File for sandboxing and trying out code
int main(int argc, char **argv) {
  // Add your code

  // Exercise 1
  node* list = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)
        )
      )
    )
  );
  print_list(list);

  // Exercise 2
  printf("\n\nSum of squares is: %d\n", sum_squares(list));

  node* test_list = make_node(1, NULL);
  print_list(test_list);
  printf("\n\nSum of squares is: %d\n", sum_squares(test_list));

  // Exercise 3
  printf("\n\n");
  print_list(list);
  printf("\n\n");
  print_list(map(list, square));

  // Exercise 4
  struct tree_node *root = NULL;
  Initialize(root);
  printf("\n\n");
  root = Insert(20, root);
  root = Insert(10, root);
  root = Insert(40, root);
  root = Insert(5, root);
  root = Insert(9, root);
  root = Insert(3, root);
  root = Insert(45, root);
  root = Insert(2, root);
  root = Insert(11, root);
  root = Insert(8, root);
  root = Insert(10, root);
  print_tree(root, 2);

  if(Contains(20, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(10, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(40, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(5, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(9, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(3, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(45, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(2, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(11, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(8, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(10, root) == 1) printf("Contains\n\n"); else printf("DONT Contains\n\n");

  if(Contains(1, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(4, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(6, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(7, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");
  if(Contains(47, root) == 1) printf("Contains\n"); else printf("DONT Contains\n");

  Remove(9, root);
  Remove(7, root);
  print_tree(root, 2);
  
  //print_tree(Remove(5, root), 2);


  root = Insert(-1, root);
  root = Insert(-1, root);
  printf("\n\n\n");
  print_tree(root, 2);
  Remove(-1, root);
  printf("\n\n\n");
  print_tree(root, 2);

  return 0;
}