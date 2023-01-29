#include <stdio.h>
//for malloc function
#include <stdlib.h>

struct node
{
    int data;
    //point the next node
    struct node *next;
    //point the previous node
    struct node *prev;
    /* data */
};

int choice, size, i, pos;
struct node *head, *tail, *temp;

//display the node list
void display()
{
    temp = head;
    printf("The current nodes are: ");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nThe value of head is : %d", head->data);
    printf("\nThe value of tail is : %d", tail->data);
}

//insert the first set of nodes
void insertNodes()
{
    printf("Enter the number of nodes you want to insert: ");
    scanf_s("%d", &size);
    printf("Enter the nodes: \n");
    while (i < size)
    {
        struct node *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        scanf_s("%d", &newNode->data);
        newNode->prev = newNode->next = 0;
        if (head == 0)
        {
            head = tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        i++;
    }
}

//function to delete the first node
void deleteFirstNode()
{
    temp = head;
    head = head->next;
    head->prev = 0;
    free(temp);
    display();
}
//funtion to delete the last node
void deleteLastNode()
{
    temp = tail;
    tail = tail->prev;
    tail->next = 0;
    free(temp);
    display();
}
//deletes a node from a specified position
void deleteFromPos()
{
    temp = head;
    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    display();
}

int main()
{
    insertNodes();
    display();
options:
    printf("\nWhich deletion operation do you want to execute: \n");
    printf("To delete first node, enter : 1\n");
    printf("To delete last node, enter : 2\n");
    printf("To delete from a specified position, enter : 3 \n");

    printf("Enter your choice: ");
    scanf_s("%d", &choice);

    if (choice == 1)
    {
        deleteFirstNode();
    }
    else if (choice == 2)
    {
        deleteLastNode();
    }
    else if (choice == 3)
    {
        printf("\nEnter the node position you want to delete: ");
        scanf_s("%d", &pos);
        if (pos < 1 || pos > size)
        {
            printf("** The position is out or range ** \n");
            goto options;
        }
        else if (pos == 1)
        {
            deleteFirstNode();
        }
        else if (pos == size)
        {
            deleteLastNode();
        }
        else
        {
            deleteFromPos();
        }
    }
    return 0;
}
