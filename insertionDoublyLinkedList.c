#include <stdio.h>
//for malloc function
#include <stdlib.h>

struct node
{
    int data;
    //point next node
    struct node *next;
    //point previous node
    struct node *prev;
};

//point the first node
struct node *head;
//point the last node
struct node *tail;
//temporarily stores a node during traversal
struct node *temp;


int choice = 1;
int size, pos, i = 0;

// Help store the initial node list
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

//insert a node at the beginning of DLL
void insertNodeBeg()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert in the beginning \n");
    scanf_s("%d", &newNode->data);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    printf("The new value of head is: %d", head->data);
}

//insert a node at the end of DLL
void insertNodeEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to insert in the beginning \n");
    scanf_s("%d", &newNode->data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    printf("The value of tail is : %d", tail->data);
}

//displays the doubly linked list
void display()
{
    temp = head;
    printf("\nThe following are the current nodes:\n");
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//inserts node at specified position
void insertNodePos()
{
    struct node *newNode, *temp;

    temp = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to  insert in the given position \n");
    scanf_s("%d", &newNode->data);

    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next->prev = newNode;
    display();
}

// insert nodes after a given specified position
void insertNodeAfterPos()
{
    struct node *newNode, *temp;
    temp = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value to  insert in the given position \n");
    scanf_s("%d", &newNode->data);

    for (i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next->prev = newNode;
    display();
}

int main()
{

    insertNodes();
    display();
    printf("The value of tail is : %d\n", tail->data);
    printf("The value of head is : %d\n \n", head->data);
options:
    printf("To Insert at beginning, enter: 1\n");
    printf("To Insert at end, enter: 2\n");
    printf("To Insert at a position, enter :3\n");
    printf("To Insert at after a position position, enter :4\n");
    printf("Press 0 to quit\n\n");

    printf("Please enter your option: ");
    scanf_s("%d", &choice);

    if (choice == 1)
    {
        insertNodeBeg();
    }
    else if (choice == 2)
    {
        insertNodeEnd();
    }
    else if (choice == 3)
    {

        printf("Enter the position to insert the node: ");
        scanf_s("%d", &pos);
        if (pos < 1 || pos > size)
        {
            printf("\nInvalid Insertion Position\n\n");
            goto options;
        }
        else if (pos == 1)
        {
            insertNodeBeg();
        }
        else
        {
            insertNodePos();
        }
    }
    else if (choice == 4)
    {
        printf("Enter the position to insert after");
        scanf_s("%d", &pos);
        if (pos < 1 || pos > size)
        {
            printf("\nYou've entered an invalid position\n\n");
            goto options;
        }
        else if (pos == size)
        {
            insertNodeEnd();
        }
        else
        {
            insertNodeAfterPos();
        }
    }

    return 0;
}
