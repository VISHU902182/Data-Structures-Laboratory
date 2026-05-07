#include<stdio.h>

int main()
{
    int dq[100];
    int front = -1;
    int rear = -1;
    int size,ch,x;

    printf("Enter size of deque: ");
    scanf("%d",&size);

    do
    {
        printf("\n1.Insert Beginning");
        printf("\n2.Delete End");
        printf("\n3.Display");
        printf("\n4.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:

                if(front==0)
                {
                    printf("No space at beginning");
                }
                else
                {
                    printf("Enter element: ");
                    scanf("%d",&x);

                    if(front==-1)
                    {
                        front=rear=0;
                    }
                    else
                    {
                        front--;
                    }

                    dq[front]=x;
                }

                break;

            case 2:

                if(front==-1)
                {
                    printf("Deque Empty");
                }
                else
                {
                    printf("Deleted: %d",dq[rear]);

                    if(front==rear)
                    {
                        front=rear=-1;
                    }
                    else
                    {
                        rear--;
                    }
                }

                break;

            case 3:

                if(front==-1)
                {
                    printf("Deque Empty");
                }
                else
                {
                    printf("Deque: ");

                    for(int i=front;i<=rear;i++)
                    {
                        printf("%d ",dq[i]);
                    }
                }

                break;
        }

    }while(ch!=4);

    return 0;
}