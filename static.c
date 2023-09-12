int main()
{
     int i;
     int a[10];
     for ( i = 0; i < 10; i++)
     a[i] = i;

     for(i = 10; i - 1; i--)
     printf("i: %d a[i]: %d\n",i, a[i]);
     
}