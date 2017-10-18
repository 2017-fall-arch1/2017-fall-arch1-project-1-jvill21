#ifndef bst_included
#define bst_included


/* create the tree node structure */
typedef struct bstNode {
  char *name;
  struct bstNode *left;
  struct bstNode *right;
} bstNode;


/* create a new tree node */
bstNode *newNode(char *name);


/* insert a new node into the tree */
bstNode* insert (bstNode* root, char *name);


/* delete a node from the tree */
bstNode* delete(bstNode* root, char *name);

/* create a new tree structure */
bstNode *createTree(bstNode *root);


/* add a new name to a text file */
void addName(char name[]);

/* print the contents of the tree in alphabetical order */
void inOrderPrint(bstNode *root);

/* create the user interface */
void userMenu();


#endif
