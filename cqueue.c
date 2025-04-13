// program to implement circular queue;
#include <stdio.h>
#include <stdlib.h>
#define max 5
struct cqueue
{
    int front;
    int rear;
    int arr[max];
};
struct cqueue *cq;
void enqueue()
{
    if (cq->front == (cq->rear + 1) % max)
    {
        printf("\n queue is full");
    }
    else
    {
        int val;
        printf("\n enter the data:");
        scanf("%d", &val);
        cq->rear = (cq->rear + 1) % max;
        cq->arr[cq->rear] = val;
    }
}

void dequeue()
{
    if (cq->front == cq->rear)
    {
        printf("\n queue is empty");
    }
    else
    {
        cq->front = (cq->front + 1) % max;
        printf("\n deleted item is %d", cq->arr[cq->front]);
    }
}

void show()
{
    int x, i;
    if (cq->front == cq->rear)
    {
        printf("\n queue is empty");
    }
    else
    {
        x = (cq->front + 1) % max;
        for (i = x; i != cq->rear; i = (i + 1) % max)
        {
            printf("\n %d", cq->arr[i]);
        }
        printf("\n %d", cq->arr[i]);
    }
}
int main()
{
    cq = (struct cqueue *)malloc(sizeof(struct cqueue));
    cq->rear = cq->front = max - 1;

    int ch;
    while (1)
    {
        printf("\n enter 1 to input data \n 2 to delete data \n 3 to show citcular queue data");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);
        default:
            printf("\n wrong input!!!");
        }
    }
    return 0;
}