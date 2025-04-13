// Program to implement linear queue;
#include <stdio.h>
#include <stdlib.h>
#define max 10

struct Lqueue
{
    int arr[max];
    int front;
    int rear;
};
struct Lqueue *q;

void enq()
{
    if (q->rear == max - 1)
    {
        printf("\n queue is full");
    }
    else
    {
        int dat;
        printf("\n enter data::");
        scanf("%d", &dat);
        q->rear += 1;
        q->arr[q->rear] = dat;
    }
}
void deq()
{
    if (q->rear < q->front)
    {
        printf("\n queue is empty");
    }
    else
    {
        printf("\n deleted item is %d", q->arr[q->front]);
        q->front += 1;
    }
}
void show()
{
    if (q->rear < q->front)
    {
        printf("\n queue is empty");
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d", q->arr[i]);
        }
    }
}
int main()
{

    q = (struct Lqueue *)malloc(sizeof(struct Lqueue));
    q->front = 0;
    q->rear = -1;
    int ch;
    while (1)
    {
        printf("\n enter \n 1 to inser data \n 2 to delete data \n 3 to show data \n 4 to exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("\n wrong input!!!");
            break;
        }
    }
    return 0;
}