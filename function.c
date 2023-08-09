int add(int a, int b) // prototype function
{
     int c;
     c = a + b;
     return (c);
}

int main()
{
     int x,y,z;
     x = 10;
     y = 49;
     z = (add(x,y)); // actual parameteres
     printf("sum is %d", z);
}