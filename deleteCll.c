#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *tail;

void createCll()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    if (tail == 0)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void delFromBeg()
{
    struct node *temp;
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void delFromEnd(int length)
{
    struct node *currentNode, *nextNode;
    currentNode = tail->next;
    int i = 0;
    while (i < (length - 2))
    {
        currentNode = currentNode->next;
        i++;
    }
    nextNode = currentNode->next;
    currentNode->next = nextNode->next;
    tail = currentNode;
    free(nextNode);



}

void delFromPos(int length)
{
    struct node *currenNode, *nextNode, *prevNode;
    int Pos, i = 0;
    printf("Enter the position to delete from: ");

    scanf("%d", &Pos);
    if (Pos == 1)
    {
        delFromBeg();
    }
    else if (Pos == length)
    {
        delFromEnd(length);
    }
    else
    {

        currenNode = tail->next;
        while (i < (Pos - 1))
        {
            prevNode = currenNode;
            currenNode = currenNode->next;
            i++;
            /* code */
        }
        nextNode = currenNode->next;
        prevNode->next = nextNode;
        free(currenNode);
    }
}

void displayCll(int length)
{
    printf("The entered data is: ");
    int i = 0;
    struct node *temp;
    temp = tail->next;
    while (i < length)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        i++;
    }
}

int main()
{
    int choice, length, i = 0;
    printf("Enter the length of of the Linked List: ");
    scanf("%d", &length);
    while (i < length)
    {
        createCll();
        i++;
    }
    displayCll(length);
    printf("\nEnter 1 to Delete from beginning: \nEnter 2 to Deleter from End:\nEnter 3 to Delete from a position\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        delFromBeg();
        displayCll(length - 1);
        break;
    case 2:
        delFromEnd(length);
        displayCll(length - 1);
        break;
    case 3:
        delFromPos(length);
        displayCll(length - 1);
        break;
    default:
        break;
    }
}
