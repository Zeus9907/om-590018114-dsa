
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// A structure to represent a stack
struct Stack {
    int top;
    int size;
    int* array;
};



struct Stack* createStack(int size)
{
    struct Stack* stack
        = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array
        = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->size - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

// Function to add an item to stack.
void push(struct Stack* stack, int data)
{
    if (isFull(stack)) {
        printf("Overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
    printf("%d pushed to stack\n",data);
}

// Function to remove an item from stack.
int pop(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Underflow\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to return the top from stack
int peek(struct Stack* stack)
{
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}




int main()
{
    struct Stack* stack = createStack(100);

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("%d popped from stack\n", pop(stack));
    printf("Top element is %d\n", peek(stack));



    return 0;
}
