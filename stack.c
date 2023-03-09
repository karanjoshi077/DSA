#include <stdio.h>
#define MAXSIZE 50
int s[MAXSIZE];
int top;
void push(void);
int  pop(void);
void display(void);
 void main ()
{
    int choice;
    int option = 1;
    top = -1;
 
    printf ("STACK OPERATION\n");
    while (option)
    {
        printf ("      1    -->    PUSH               \n");
        printf ("      2    -->    POP               \n");
        printf ("      3    -->    DISPLAY               \n");
        printf ("      4    -->    EXIT           \n");
        printf ("Enter your choice\n");
        scanf    ("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        fflush (stdin);
        printf ("Do you want to continue(Type 0 or 1)?\n");
        scanf    ("%d", &option);
    }
}
void push ()
{
    int num;
    if (top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return;
    }
    else
    {
        printf ("Enter the element to be pushed\n");
        scanf ("%d", &num);
        top = top + 1;
        s[top] = num;
    }
    return;
}
int pop ()
{
    int num;
    if (top == - 1)
    {
        printf ("Stack is Empty\n");
        return (top);
    }
    else
    {
        num = s[top];
        printf ("poped element is = %d\n", s[top]);
        top = top - 1;
    }
    return(num);
}
void display ()
{
    int i;
    if (top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = top; i >= 0; i--)
        {
            printf ("%d\n", s[i]);
        }
    }
    printf ("\n");
}