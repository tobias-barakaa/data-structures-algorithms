#define OK 0
#define QUEUE_EMPTY -1  
#define OUT_OF_SPACE -2
#define MAXQUEUE 100

int queue[MAXQUEUE];
int rear = -1, front = -1;

int addQueue(int element)
{
     if (front + 1 >= MAXQUEUE)
     return (OUT_OF_SPACE);
     queue[++front] = element;
     return (OK);
}

int delqueue()
{
     if(front == rear) /* ques is empty*/
     error();
     return(queue[++rear]);
}

int q_empty()
{
     if (front == rear)
     return (QUEUE_EMPTY);
     return (OK);


}

int quesize()
{
     return (front - rear);
}