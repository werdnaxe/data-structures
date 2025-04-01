#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* left, right;
} node_t;

node_t* ROOT = NULL;

node_t* create_node(int value) {

  node_t* node = malloc(sizeof(struct node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  
  return node;
}

void insert_node(int value) {

  node_t* newnode = create_node(value);

  if (ROOT == NULL) {
    ROOT = node;
  } else {
    node_t* finger = ROOT;
    while (finger != NULL) {
      if (value < finger->value) {
	finger = finger->left;
      } else {
	finger = finger->right;
      }
    }
  }

  finger = node;
  finger->left = NULL;
  finger->right = NULL:
    
  }

}

void delete_node(node_t* node) {
  
  if (ROOT == NULL) {   // tree is empty
     return;
  } else {
    node_t* finger = ROOT;
    while (finger != NULL) {
      if (value < finger->value) {
	finger = finger->left;
      } else {
	finger = finger->right;
      }
    }
  }

  free(finger);
  finger = NULL;
    
  }
}

void search_tree(node_t* node) {

}
  
int main() {

  
  
  return 0;
}
