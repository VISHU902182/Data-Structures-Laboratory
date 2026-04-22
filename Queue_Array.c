#include<stdio.h>

int main()
{
    int q[100];
    int front=-1, rear=-1;
    int size, ch, x;

    printf("Enter size of queue: ");
    scanf("%d",&size);

    do{
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.isEmpty 5.isFull 6.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                if(rear==size-1)
                    printf("Queue is Full");
                else{
                    printf("Enter value: ");
                    scanf("%d",&x);
                    if(front==-1) front=0;
                    rear++;
                    q[rear]=x;
                }
                break;

            case 2:
                if(front==-1 || front>rear)
                    printf("Queue is Empty");
                else{
                    printf("Deleted: %d",q[front]);
                    front++;
                }
                break;

            case 3:
                if(front==-1 || front>rear)
                    printf("Queue Empty");
                else
                    printf("Front element: %d",q[front]);
                break;

            case 4:
                if(front==-1 || front>rear)
                    printf("Queue is Empty");
                else
                    printf("Queue not Empty");
                break;

            case 5:
                if(rear==size-1)
                    printf("Queue is Full");
                else
                    printf("Queue not Full");
                break;
        }

    }while(ch!=6);

    return 0;
}