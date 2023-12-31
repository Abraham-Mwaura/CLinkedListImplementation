#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
    /* data */
} *head, *tail;

void createDoublyLinkedList()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = newNode->prev = 0;
    if (head == 0)
    {
        head = tail = newNode;
        newNode->next = newNode->prev = newNode;
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtBeginning()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &newNode->data);
    head->prev = newNode;
    tail->next = newNode;
    newNode->next = head;
    newNode->prev = tail;
    head = newNode;
}
void insertAtEnd()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &newNode->data);
    tail->next = newNode;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = tail;
    tail = newNode;
}
void insertAtPosition(int length)
{
    int position, i = 0;

    printf("enter the position you wish to insert: ");
    scanf("%d", &position);
    if (position == 1)
    {
        insertAtBeginning();
    }
    else if (position == length + 1)
    {
        insertAtEnd();
    }
    else
    {
        struct node *temp, *newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d", &newNode->data);
        temp = head;
        while (i < position - 2)
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void displayDoublyLinkedList(int length)
{
    struct node *temp;
    temp = head;
    int i = 0;
    while (i < length)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    int length, choice, i = 0;
    printf("Enter the length of the doublyLinkedList: ");
    scanf("%d", &length);
    while (i < length)
    {
        createDoublyLinkedList();
        i++;
    }
    displayDoublyLinkedList(length);
    printf("\nTo Insert at Beginning enter 1\nTo Insert at the end enter 2\nTo insert at position enter 3\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertAtBeginning();
        length++;
        displayDoublyLinkedList(length);
        break;
    case 2:
        insertAtEnd();
        length++;
        displayDoublyLinkedList(length);
        break;

    case 3:
        insertAtPosition(length);
        length++;
        displayDoublyLinkedList(length);
        break;
    default:
        break;
    }
}