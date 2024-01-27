#include <stdio.h>
#include <stdlib.h>

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

void push(stack *s, int val)
{
    if (is_full(s))
    {
        printf("stack overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(stack *s)
{
    if (is_empty(s))
    {
        printf("underflow\n");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

 void  print_stack(stack* s)
 {
     int temp=s->top;
     while(temp--)  
     {
        printf("the index : %d and value is: %d \n", temp,s->arr[temp] );
     }
 }

int main()
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (is_empty(s))
    {
        for (int i = 0; i < 10; i++)
        {
            push(s, i*i);
        }
    }
    // int temp = s->top;

    // while (temp != 0)
    // {
    //     printf("%d ", s->arr[temp]);
    //     temp--;
    // }


    // printf("\n");
    // temp = s->top;


    // pop(s);


    // while (temp != 0)
    // {
    //     printf("%d ", s->arr[temp]);
    //     temp--;
    // }

    print_stack(s);
    pop(s);
    printf("\n");
    print_stack(s);

    free(s->arr);

    free(s);
    return 0;
}