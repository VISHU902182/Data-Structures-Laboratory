#include<stdio.h>

int stack[100];
int top = -1;
int size;

int main()
{
    int ch, x;

    printf("Enter size of stack: ");
    scanf("%d",&size);

    do{
        printf("\n1.Push\n2.Pop\n3.Top\n4.isEmpty\n5.isFull\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        if(ch==1)
        {
            if(top==size-1)
                printf("Stack Full\n");
            else
            {
                printf("Enter element: ");
                scanf("%d",&x);
                top++;
                stack[top]=x;
            }
        }
        else if(ch==2)
        {
            if(top==-1)
                printf("Stack Empty\n");
            else
            {
                printf("Deleted element %d\n",stack[top]);
                top--;
            }
        }
        else if(ch==3)
        {
            if(top==-1)
                printf("Stack Empty\n");
            else
                printf("Top element %d\n",stack[top]);
        }
        else if(ch==4)
        {
            if(top==-1)
                printf("Stack is Empty\n");
            else
                printf("Stack is Not Empty\n");
        }
        else if(ch==5)
        {
            if(top==size-1)
                printf("Stack is Full\n");
            else
                printf("Stack is Not Full\n");
        }

    }while(ch!=6);

    return 0;
}
