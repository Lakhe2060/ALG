// Program to implement stack operation;

#include <stdio.h>
#include <stdlib.h>
#define max 5

int tos = -1;
int stack[max];
void push()
{
    if (tos == max - 1)
    {
        printf("\n stack is full");
    }
    else
    {
        int dat;
        printf("\n enter data to push:\t");
        scanf("%d", &dat);
        tos += 1;
        stack[tos] = dat;
    }
}
void pop()
{
    if (tos == -1)
    {
        printf("\n stack is empty!");
    }
    else
    {
        printf("\n deleted data is %d", stack[tos]);
        tos -= 1;
    }
}
void show()
{
    if (tos == -1)
    {
        printf("\n stack is empty!!");
    }
    else
    {
        printf("\n stack is:");
        for (int i = tos; i >= 0; --i)
        {
            printf("\n %d", stack[i]);
        }
    }
}
int main()
{
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
        char w;
        printf("\n do you wish to continue?::y or n");
        scanf("%c", &w);
    } while (ch != 4);
    return 0;
}