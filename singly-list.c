#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <locale.h>

struct node
{
     int info;
     struct node *link;
};

struct node *createList(struct node *start);

void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start, int x);
struct node *insertInBeginning(struct node *start, int data);
void insertAtEnd(struct node *start, int data);
void insertAfter(struct node *start, int data, int x);
struct node *insertBefore(struct node *start, int data, int x);
struct node *insertAtPosition(struct node *start, int data, int k);
struct node *deleteNode(struct node *start, int data);
struct node *reverseList(struct node *start);

main()
{
     struct node *start = NULL;
     int choice, data, x, k;
     start = createList(start);


     while(1)
     {
          printf("\n");
          printf("1.Display List\n");
          printf("2.Count the number of nodes\n");
          printf("3.Search for an element\n");
          printf("4.Add to empty list / Add at beginning");
          printf("5.Add at end of the list\n");
          printf("6. Add a node after a specified node\n");
          printf("7.Add a node before a specified node\n");

          printf("Enter your choice:");
          scanf("%d", &choice);

          if(choice == 11)
          break;
          switch(choice)
          {
               case 1:
               displayList(start);
               break;
               case 2:
               countNodes(start);
               break;
               case 3:
               printf("Enter the element to be searched:");
               scanf("%d", &data);
               break;
               case 4:
               printf("Enter the element to be inserted:");
               scanf("%d", &data);
               break;
               case 5:
               printf("Enter the element to be inserted");
               scanf("%d", &data);
               insertAtEnd(start, data);
               break;
               case 6:
               printf("Enter the element to be inserted");
               scanf("%d", &data);
               printf("Enter the element which to insert:");
               scanf("%d", &x);
               insertAfter(start, data,x);
               break;
               case 7:
               printf("Enter the element to be inserted :");
               scanf("%d", &x);
               printf("Enter the element before which to insert :");
               scanf("%d", &x);
               start= insertBefore(start,data,x);
               break;
               case 8:
               printf("Enter the element to be inserted:");
               scanf("%d", &data);
               printf("Enter the position at which to insert:");
               scanf("%d", &k);
               start=insertAtPosition(start, data,k);
               break;
               case 9:
               printf("Enter the element to be deleted :");
               scanf("%d", &data);
               start=deleteNode(start, data);
               break;
               case 10:
               start=reverseList(start);
               break;
               default:
               printf("Wrong choice\n");
          }
     }
}

// End of main function;
struct node *createList(struct node *start)
{
     int i,n,data;
}


