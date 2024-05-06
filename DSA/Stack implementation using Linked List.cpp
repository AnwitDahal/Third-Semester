#include <stdio.h>
#include <stdlib.h>

// Structure to create a node with data and the next pointer
struct node {
    int info;
    struct node *ptr;
};

struct node *top = NULL;
int count = 0;

// Push() operation on a stack
void push(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->info = data;
    temp->ptr = top;
    top = temp;
    count++;
    printf("Node is inserted\n\n");
}

// Pop operation on a stack
int pop() {
    struct node *top1;
    int popped;

    if (top == NULL) {
        printf("\nStack Underflow\n");
        return -1; // Returning -1 to indicate stack underflow
    } else {
        top1 = top;
        popped = top1->info;
        top = top->ptr;
        free(top1);
        count--;
        return popped;
    }
}

// Display the elements of the stack
void display() {
    struct node *top1 = top;

    if (top1 == NULL) {
        printf("\nStack Underflow\n");
        return;
    }

    printf("The stack is: \n");
    while (top1 != NULL) {
        printf("%d -> ", top1->info);
        top1 = top1->ptr;
    }
    printf("NULL\n\n");
}

int main() {
    int choice, value;
    printf("\nImplementation of Stack using Linked List\n");
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                printf("Popped element is: %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nWrong Choice\n");
        }
    }
    return 0;
}

