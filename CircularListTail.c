#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *tail;

int choice = 1;

void createCll()
{

    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void displayCll()
{
    struct node *temp;
    if (tail == 0)
    {
        printf("The list is empty");
        /* code */
    }
    else
    {
        temp = tail->next;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

int main()
{
    while (choice != 0)
    {
        createCll();
        printf("Enter any number to insert a node, 0 to quit insertion: ");
        scanf("%d", &choice);
    }
    displayCll();
}