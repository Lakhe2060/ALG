// c program to implement the singly linked list
#include <stdio.h>
#include <stdlib.h>

// creation of Linked List
struct list
{
    int info;
    struct list *next;
};
struct list *ptr, *head;

// insert node at the beginning
void infirst()
{
    struct list *newnode;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("\n enter data to insert\t");
    scanf("%d", &newnode->info);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

// node at the end of the linked list;
void inlast()
{
    struct list *newnode, *temp;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("\n enter data to insert\t");
    scanf("%d", &newnode->info);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// insert node at the specified position
void inposition()
{
    int pos;
    struct list *newnode, *temp;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("\n enter data to insert\t");
    scanf("%d", &newnode->info);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = NULL;
    }
    else
    {
        printf("\n enter the position where you want to insert the node:\t");
        scanf("%d", &pos);
        temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// delete a node from the beginning of the sll
void delfirst()
{
    struct list *temp;
    // case 1:
    if (head == NULL)
    {
        printf("\n SLL is empty");
    }
    // case 2:
    else if (head->next == NULL)
    {
        printf("\n deleted data item is %d", head->info);
        head = NULL;
    }
    else
    {
        temp = head;
        printf("\n deleted data item is %d", head->info);
        head = temp->next;
        free(temp);
    }
}

// delete a node from the end of the sll;
void dellast()
{
    // case 1:
    if (head == NULL)
    {
        printf("\n sll is empty!");
    }
    else if (head->next == NULL)
    {
        printf("\n data is%d", head->info);
        head = NULL;
    }
    else
    {
        struct list *temp;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("\n deleted data is%d", temp->info);
        temp->next = NULL;
    }
}

// delete a node form specific location;
void delposition()
{
    int pos;
    if (head == NULL)
    {
        printf("\n sll is empty");
    }
    else if (head->next == NULL)
    {
        printf("\n deleted data is %d", head->info);
        head = NULL;
    }
    else
    {
        struct list *temp;
        temp = head;
        printf("\n enter the position of the node you want to delete");
        scanf("%d", &pos);
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        printf("\n deleted data is %d", temp->info);
       
    }
}

// display the data;
void display()
{
    struct list *temp;
    printf("\n data of the sll is:");
    temp = head;
    while (temp != NULL)
    {
        printf("\n%d", temp->info);
        temp = temp->next;
    }
}

int main()
{
    int cha;
    ptr = (struct list *)malloc(sizeof(struct list));

    while (1)
    {
        printf("\n enter \n 1 to insert data at the start\n 2 to insert the data at the end\n 3 to insert data to any specific position\n4 to delete form beginning\n 5 to delete from end\n 6 to delete data from any specific position\n 7 to display the sll data\n 0 to exit");
        scanf("%d", &cha);
        switch (cha)
        {
        case 1:
            infirst();
            break;
        case 2:
            inlast();
            break;
        case 3:
            inposition();
            break;
        case 4:
            delfirst();
            break;
        case 5:
            dellast();
            break;
        case 6:
            delposition();
            break;
        case 7:
            display();
            break;
        case 0:
            exit(0);

        default:
            printf("\n wrong input");
        }
    }
    return 0;
}
