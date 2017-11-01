#include<stdio.h>
#define MAX 10
int Q[MAX];
int front = -1 , rear = -1;

int main()
{
   int choice , item ;
   while(1)
   {
       printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        printf("Enter the element : ");
        scanf("%d",&item);
        enq(item);
        break;
       case 2:
        printf("Dequeued element is %d\n",deq());
        break;
       case 3:
        display();
        break;
       default:
        exit(0);
       }
   }
    return 0;
}
void enq(int item)
{
    if(isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if(rear == -1)
    {
        front = rear = 0;
    }
    else
        rear++;
    Q[rear] = item;
}
int deq()
{
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    int item = Q[front];
    front++;
    if(front == rear + 1)
        front = rear = -1;
    return item;;
}
void display()
{
    if(isEmpty())
    {
        printf("Queue Empty\n");
        return;
    }
    int i;
    for(i = front ; i <= rear ; i++)
        printf("%d ",Q[i]);
    printf("\n");
}
int isEmpty()
{
    if((front == -1 && rear == -1) )
        return 1;
    return 0;
}
int isFull()
{
    if(rear == MAX-1)
        return 1;
    return 0;
}
