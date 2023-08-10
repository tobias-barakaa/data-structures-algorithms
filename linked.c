#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Node
{
    int data; // data stored in node
    struct Node *link; // pointer to next node
};

struct Node *head_ptr = NULL;
struct Node *tail_ptr = NULL;

size_t list_length(struct Node * head_ptr)
{
struct Node *cursor;
size_t answer=0;
for(cursor=head_ptr; cursor != NULL; cursor=cursor->link)
answer++;
return answer;
}