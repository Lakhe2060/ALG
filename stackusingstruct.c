// Program to implement stack operation using
#include <stdio.h>
#include <stdlib.h>
#define max 5

struct stack
{
    int tos;
    int arr[max];
};
struct stack *st;

void push()
{
    if (st->tos == max - 1)
    {
        printf("\n stack is full");
    }
    else
    {
        int dat;
        printf("\n enter data to push:\t");
        scanf("%d", &dat);
        st->tos += 1;
        st->arr[st->tos] = dat;
    }
}
void pop()
{
    if (st->tos == -1)
    {
        printf("\n stack is empty!");
    }
    else
    {
        printf("\n deleted data is %d", st->arr[st->tos]);
        st->tos -= 1;
    }
}
void show()
{
    if (st->tos == -1)
    {
        printf("\n stack is empty!!");
    }
    else
    {
        printf("\n stack is:");
        for (int i = st->tos; i >= 0; --i)
        {
            printf("\n %d", st->arr[i]);
        }
    }
}
int main()
{
    st = (struct stack *)malloc(sizeof(struct stack));
    st->tos = -1;
    int ch;
    do
    {
        printf("\n enter:\n 1 to push data \n 2 to pop data \n 3 to show data");
        scanf("\n %d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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

    } while (ch != 4);
    free(st);
    return 0;
}