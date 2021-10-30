#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 
// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
 
    printf("NULL\n");
}
 
// Helper function to insert a new node at the beginning of the linked list
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Function takes the node from the front of the source and moves it
// to the front of the destination
void moveNode(struct Node** destRef, struct Node** sourceRef)
{
    // if the source list empty, do nothing
    if (*sourceRef == NULL) {
        return;
    }
 
    struct Node* newNode = *sourceRef;      // the front source node
    *sourceRef = (*sourceRef)->next;        // advance the source pointer
    newNode->next = *destRef;               // link the old dest off the new node
    *destRef = newNode;                     // move dest to point to the new node
}
 
// Takes two lists sorted in increasing order and merge their nodes
// to make one big sorted list, which is returned
struct Node* sortedMerge(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;     // point to the last result pointer
 
    while (1)
    {
        if (a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if (b == NULL)
        {
            *lastPtrRef = a;
            break;
        }
 
        if (a->data <= b->data) {
            moveNode(lastPtrRef, &a);
        }
        else {
            moveNode(lastPtrRef, &b);
        }
 
        // tricky: advance to point to the next `.next` field
        lastPtrRef = &((*lastPtrRef)->next);
    }
 
    return result;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct Node *a = NULL, *b = NULL;
    for (int i = n - 1; i >= 0; i = i - 2) {
        push(&a, keys[i]);
    }
 
    for (int i = n - 2; i >= 0; i = i - 2) {
        push(&b, keys[i]);
    }
 
    // print both lists
    printf("First List: ");
    printList(a);
 
    printf("Second List: ");
    printList(b);
 
    struct Node* head = sortedMerge(a, b);
    printf("After Merge: ");
    printList(head);
 
    return 0;
}

