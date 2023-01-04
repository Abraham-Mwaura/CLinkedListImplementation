#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
    /* data */
};

struct node *head;
struct node *temp;
void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{

    int choice = 1;
    while (choice)
    {   
        struct node *newNode;
        newNode = (struct node *) malloc(sizeof(struct node));
        printf("Enter the data:\n ");
        scanf("%d", &newNode->data);
        newNode->prev = newNode->next = 0;
        if (head == 0)
        {
            head = temp = newNode;
            head = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
        printf("Enter 1 to continue,0 to quit:\n");
        scanf(choice);
    }

    display();

    return 0;
}
