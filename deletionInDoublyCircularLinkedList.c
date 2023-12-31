#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;

} *head, *tail;

void createDoublyCircularLinkedList()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    if (tail == 0)
    {
        head = tail = newNode;
        newNode->prev = head;
        newNode->next = tail;
        /* code */
    }
    else
    {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void deleteFromBeginning()
{
    struct node *temp;
    temp = head;
    tail->next = head->next;
    head->next->prev = tail;
    head = head->next;
    free(temp);
}

void deleteFromEnd()
{
    struct node *temp;
    temp = tail;
    head->prev = tail->prev;
    tail->prev->next = head;
    tail = tail->prev;
    free(temp);
}

void deleteFromPosition(int length)
{
    struct node *temp;
    int Position, i = 0;
    printf("Enter the position to delete from");
    scanf("%d", &Position);
    if (Position == 1)
    {
        deleteFromBeginning();
        /* code */
    }
    else if (Position == length + 1)
    {
        deleteFromEnd();
    }
    else
    {
        temp = head;
        while (i < Position - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void displayDoublyCircularLinkedList(int length)
{
    struct node *temp;
    int i = 0;
    temp = head;
    while (i < length)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
        /* code */
    }
}
int main()
{
    int length, i = 0, Choice;
    printf("Enter the length of the Doubly Linked List: ");
    scanf("%d", &length);
    while (i < length)
    {
        createDoublyCircularLinkedList();
        i++;
        /* code */
    }
    displayDoublyCircularLinkedList(length);

    printf("\n1 : Delete from beginning\n2 : Delete from end\n3 : Delete from Position \nEnter Option: ");
    scanf("%d", &Choice);

    switch (Choice)
    {
    case 1:
        deleteFromBeginning();
        length--;
        displayDoublyCircularLinkedList(length);
        /* code */
        break;
    case 2:
        deleteFromEnd();
        length--;
        displayDoublyCircularLinkedList(length);
    case 3:
        deleteFromPosition(length);
        length--;
        displayDoublyCircularLinkedList(length);

    default:
        break;
    }
}