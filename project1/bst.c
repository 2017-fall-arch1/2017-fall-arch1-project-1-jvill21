#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

/* creates a new location in memory for a node */
bstNode *newNode(char *name) {
  bstNode *newNode = (bstNode *)malloc(sizeof(bstNode));
  newNode -> name = malloc(strlen(name) + 1);
  strcpy(newNode -> name, name);
  newNode -> left = NULL;
  newNode -> right = NULL;
  return newNode;
  }


/* insert a new node into the tree */
bstNode* insert(bstNode* root, char *name) {
  if (root == NULL) {
    return newNode(name);
  }
  if (strcmp(name, root->name) > 0) { // name is greater than root value
    root -> right = insert(root -> right, name);
  }
  else {
    root -> left = insert(root ->left, name);
  }
  return root;
}


/* delete a node from the tree */
bstNode* delete(bstNode* root, char *name) {

  if (root == NULL) {
    return root;
  }
  else if (strcmp(name, root->name) > 0) {
   root->right = delete(root->right, name);
  }
  else if (strcmp(name, root->name) < 0) {
   root->left = delete(root->left, name);
  }
  else {
    if (root->left == NULL && root->right == NULL) { // if a node has no children
      free(root);
      root = NULL;
      return root;
    }
    else if (root->left == NULL) { // if node has only right child
      bstNode *temp = root;
      root = root->right;
      free(temp);
      return root;
    }
    else if (root->right == NULL) { // if node has only left child
      bstNode *temp = root;
      root = root->left;
      free(temp);
      return root;
    }
    // node has two children
    bstNode *temp = root;
    bstNode *min = temp;
    while (min->left != NULL) { // finds the leftmost node
      min = min->left;
    }
    temp = min;
    root->name = temp->name;
    root->right = delete(root->right, temp->name);
  }
  return root;
}
    
  

/*  create the tree from the given text file */
bstNode *createTree(bstNode *root) {
  
  FILE *file = fopen("employees.txt", "r");

  char name[45]; // who has a name longer than 45 characters...
  while (fgets(name, 45, file)) {
    name[strlen(name) - 1] = '\0';
      if (root == NULL) {
	root = insert(root, name);
      }
      else {
	insert(root, name);
      }
  }
  return root;
  }


/* add a name to the file */
void addName(char name[]) {
  FILE *file = fopen("names.txt", "a");

  fprintf(file, "%s \n", name);

  fclose(file);
}

/* prints the contents of the tree alphabetical order */
void inOrderPrint(bstNode *root) {
  if (root != NULL) {
    inOrderPrint(root -> left);
    printf("%s \n", root -> name);
    inOrderPrint(root -> right);
  }
}  

/* creates the user interface */
void userMenu() {
  printf("\nWelcome to the ACME Solutions Personal Management System!\n");
  printf("Please select the function you wish to perform:\n");
  printf("1) View list of current employees\n");
  printf("2) Add a new employee to the system\n");
  printf("3) Remove an employee from the system\n");
  printf("4) Exit the system\n");
  
}
