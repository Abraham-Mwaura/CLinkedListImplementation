#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *tail = 0;
int length, i = 0;

void createCll()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next; // set the next of newnode as the address of the head
        tail->next = newNode;       // overwrite next of tail as the newnode
        tail = newNode;
    }
}

void insertBeg()
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
        /* code */
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    printf("%d", tail->next->data);
}

void insertEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (tail == 0)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPos(int length)
{
    struct node *temp;
    int pos = 0;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position to insert the node: ");
    scanf("%d", &pos);

    if (pos > length + 1 & pos <= 0)
    {
        printf("Invalid insert position");
        /* code */
    }
    else if (pos == 1)
    {
        insertBeg();
    }
    else if (pos == length + 1)
    {
        insertEnd();
        /* code */
    }
    else
    {
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = 0;
        if (tail == 0)
        {
            tail = newNode;
            tail->next = newNode;
        }
        temp = tail->next; // set temp as the head
        int i = 0;
        while (i < pos - 1)
        {
            i++;
            temp = temp->next;
            /* code */
        }
        newNode->next = temp->next;
        temp->next = newNode;

        /* code */
    }
}
void displayCll()
{
    printf("\nThe Entered Linked list is: \n");
    struct node *temp;
    if (tail == 0)
    {
        printf("The list is empty");
        /* code */
    }
    else
    {
        temp = tail->next; // set temp as the head
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

int main()
{

    printf("Enter Length of Circular Linked list: ");
    scanf("%d", &length);
    while (i < length)
    {
        createCll();
        i++;
    }

    // insertBeg(&newNode);
    displayCll();
    int choice;
    printf("\nEnter 1 to insert at beginning;\nEnter 2 to insert at the end;\nEnter 3 to insert at a specificPosition\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertBeg();
        break;
    case 2:
        insertEnd();
        break;
    case 3:
        insertAtPos(length);
        break;
    default:
        break;
    }
    displayCll();
}
