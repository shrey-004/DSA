#include <stdio.h>
#include<stdlib.h>

typedef struct stack stack;

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(stack *s, int data)
{
    if (is_full(s))
    {
        printf("stack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top]=data;
    }
}

int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("stack underflow\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(stack *s, int post)
{
    if (s->top - post + 1 < 0)
    {
        printf("Invalid position \n");
        return -1;
    }
    else
    {
        return s->arr[s->top-post+1];
    }
}


int stack_top(stack * s)
{
    printf("The value at the top is %d\n", s->arr[s->top]);
}


int stack_bottom(stack* s)
{
    printf("The value at the bottom is %d\n", s->arr[0]);
}



int main()
{
    stack *s = (stack * ) malloc(sizeof(stack));
    s->size = 80;
    s->top = -1;
    s->arr= (int*) malloc ((s->size)* (sizeof(int)));
    if (is_empty(s))
    {
        for(int i=0; i<=10; i++)
        {
            push(s, i*i);
        }
    }
    for(int i=1; i<=s->top+1; i++)
    {
        printf("The value at the position %d is %d \n", i, peek(s, i));
    }
    pop(s);
    printf("------------------------------------------------------------------------------------------------------\n");
    for(int i=1; i<=s->top+1; i++)
    {
        printf("The value at the position %d is %d \n", i, peek(s, i));
    }
}

