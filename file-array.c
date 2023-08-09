#include <string.h>

// int main()
// {
//      int A[5];
//      int B[5] = {3,4,4,8,4,2};
//      // accessing an array;
//      // you come up with a variable to help you loop through

//      int i;
//      for(i = 0; i < 5; i++)
//      {
//           // print every element in B[5]
//           printf("%d", B[i]);
//      }
// }

int main()
{
     int A[4];
     A[0] = 43;
     A[1] = 48;
     A[2] = 78;
     A[3] = 8;

     printf("%d", sizeof(A[0]));
     return (0);
}