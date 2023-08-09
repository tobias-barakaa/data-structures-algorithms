// declaration
// initialisation
// deferencing in pointer
#include <stdio.h> // You need to include this header for using printf()
#include <string.h>

struct Rectangle
{
     int length;
     int breadth;
};

struct Rectangle p; // Declare a structure variable named 'p' of type 'struct Rectangle'

int main()
{
     int A[4] = {4, 4, 3, 9}; // Declare an integer array 'A' with 4 elements
     int *p; // Declare an integer pointer variable 'p'
     p = A; // Assign the base address of array 'A' to pointer 'p'
     
     for (int i = 0; i < 4; i++)
     {
          printf("%d", p[i]); // Print the elements of array 'A' using pointer 'p'
     }
     return (0);

     // // normal variable we do
     // p.length = 12; 
     // (*p).length = 20; 
     // p->length = 20; 
}


struct Square
{
     int len;
     int breadth;
};

int main()
{
     struct Square *p;
     p = (struct Square *)malloc(sizeof(struct Rectangle));
     p->len = 49;
     p->breadth = 590;
}

