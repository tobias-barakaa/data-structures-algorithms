#define MAXQUEUE 100
#define NEXT(X) ((X + 1) % MAXQUEUE)

#define OK 0
#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

int queue[MAXQUEUE];
int rear = 0, front = 0;

int cir_add(int element)
{
     if (NEXT(rear) == front)
     return (QUEUE_EMPTY);
     rear = NEXT(rear);
     queue[rear] = element;
     return (OK);
}

int cir_delet()
{
     if(front == rear) /*error*/
      cir_error();
     rear = NEXT(front);
     return(queue[front]);

}

int cir_empty()
{
     if(front == rear)
     return(QUEUE_EMPTY);
     return (OK);
}


int cir_size()
{
     return(((front-rear) + MAXQUEUE) % MAXQUEUE);
}