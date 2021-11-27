//Exercise: 5
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int stack[100],num,top=0;

int main()
{

    int num;
    printf("Enter a decimal number: ");
    scanf("%d",&num);
    decTobin(num);
}
void push(int n)
{
    if (top>=MAX)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top]=n;
    }
}
void decTobin(int num)
{
    while(num!=0)
    {
        push(num%2);
        num=num/2;
    }
    while(top!=0)
    {
        printf("%d",pop());
    }
}

int pop()
{
    int n;
    if(top==0)
    {
        printf("Stack underflow.\n");
        exit(1);
    }
    else
    {
        n=stack[top];
        top--;
    }
    return n;
}
