#include <stdio.h>
#include <string.h>

struct  Rectangle
{
     /* data */
     int length;
     int breadth;
};

// you can declare variable as you want

struct Rectangle r1;

int main()
{
        struct Rectangle r1 = {23, 24};
        printf("%d", sizeof(r1));
        return (0);

}