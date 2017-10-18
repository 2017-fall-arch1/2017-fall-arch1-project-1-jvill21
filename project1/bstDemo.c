#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


int main() {

  bstNode *root = NULL;
  root =  createTree(root);

  int selection;
  char name[45];
  while (selection != 4) {
    userMenu();
    scanf("%d", &selection);

    switch(selection) {
    case 1:
      printf("The current list of employees:\n ");
      inOrderPrint(root);
      break;
    case 2:
      printf("Please enter an employee to add to the system: ");
      // char name[45];
      scanf("%s", &name);
      addName(name);
      insert(root, name);
      printf("%s has been added to the system\n\n", name);
      break;
    case 3:
      printf("Please enter an employee to delete from the system: ");
      //  char name[45];
      scanf("%s", &name);
      delete(root, name);
      printf("%s has been deleted from the system\n\n");
      break;
    default:
      printf("Please enter a valid command\n\n");
      break;
    }
  }
  printf("Session Terminated\n");
  return 0;
}


  /*  int input = 0;
  while (input != 4) {
    userMenu();
    scanf("%i", &input);
    if (input == 1) {
      printf("\n The current list of names:\n");
      inOrderPrint(root);
    }
    else if (input == 2) {
      printf("Please enter a name to add to the system: ");
      char name[25];
      scanf("%s", name);
      addName(name);
      insert(root, name);
      printf("%s has been added to the system...\n\n", name);
    }
    else if (input == 3) {
      printf("Please enter a name to delete from the system: ");
      char name[25];
      scanf("%s", name);
      delete(root, name);
      printf("%s has been removed from the system\n\n", name);
    }
    
  }
  printf("\nExiting the System... \nThank you! Have a nice day!\n\n");
  return 0;*/
