#define OK 0
#define FALSE 0
#define TRUE 1
#define FULL 1
#define MAXSTACK 100

int top = -1;
int stack[MAXSTACK];

push(int new) 
{
     if (top + 1 >= MAXSTACK)
     return (FULL);

     stack[++top] = new;

     return (OK);
}

int pop()
{
     return (stack[top--]);
}


int empty()
{
     if(top < 0)
     return (TRUE);
     return(FALSE);
}

void reverse()
{
     int item;
     while((item = newinput()) != EOF)
     if (push(item) == FULL)  
          error();
     while (!empty()) 
     putchar(pop());
}