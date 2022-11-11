#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Insert node in tree
struct tree_node *Insert(int x, struct tree_node *t) {
  struct tree_node *newNode = malloc(sizeof(struct tree_node)); // creates node to insert
  newNode->left = NULL; // sets the node's left child to NULL
  newNode->right = NULL; // sets the node's right child to NULL
  newNode->item = x; // assigns the given value to the newly created node
  if(Empty(t) == 1) { // checks whether the tree is empty or not
    t = newNode;
  } else if(newNode->item <= t->item) { // less than or equal (left)
    if(t->left == NULL) { // if end of the tree
      t->left = newNode; // assigns node to the end
    } else {
      t->left = Insert(x, t->left); // checks deeper into the tree
    }
  } else if(newNode->item > t->item) { // greater than (right)
    if(t->right == NULL) { // if end of the tree
      t->right = newNode; // assigns node to the end
    } else {
      t->right = Insert(x, t->right); // checks deeper into the tree
    }
  } else { // inserting the node and assigning the tree's children to the node's
    newNode->left = t->left;
    newNode->right = t->right;
    t = newNode;
  }
  return t; // returns the tree
}


// Remove node from tree
struct tree_node *Remove(int x, struct tree_node *t) {
  if(t->item == x) { // if the value has been found
    if(t->left == NULL) { // checks if node has a left child or not
      struct tree_node *tempNode = t->right;
      return tempNode;
    } else if(t->right == NULL) { // checks if node has a right child or not
      struct tree_node *tempNode = t->left;
      return tempNode;
    }
    struct tree_node *tempNode = t->right; // temporary node to search for minimum value
    while(tempNode && tempNode->left != NULL) { // loops until end of left side
      tempNode = tempNode->left; // continue search
    }
    t->item = tempNode->item; // moves item to removed element's spot
    t->right = Remove(tempNode->item, t->right);
    return t; // returns the tree
  } else if(x < t->item && t->left != NULL) { // less than (left)
    t->left = Remove(x, t->left); // searches for element in left side
  } else if(x > t->item && t->right != NULL) { // greater than (right)
    t->right = Remove(x, t->right); // searches for element in right side
  }
  return t; // returns the tree
}

// Check if tree contains value
int Contains(int x, struct tree_node *t) {
  int contain = 0; // sets contains to false as default
  if(t->item == x) { // checks if list contains element
    contain = 1; // sets the contains to true if elements is included in list
  } else if(x < t->item && t->left != NULL) { // less than (left)
    contain = Contains(x, t->left); // searches further into left side
  } else if(x > t->item && t->right != NULL) { // greater than (right)
    contain = Contains(x, t->right); // searches further into right side
  }
  return contain; // returns either true or false
}

// Initialize tree
struct tree_node *Initialize(struct tree_node *t) {
  t = NULL; // creates tree
  return t; // returns the newly created tree
}

// Check if tree is empty
int Empty(struct tree_node *t) {
  if(t == NULL) { // checks if tree is empty
    return 1; // if tree empty returns true
  }
  return 0; // else returns false
}


// Not necessary since tree won't be filled
int Full(struct tree_node *t) {
  // Test if full
  return 0;
}
