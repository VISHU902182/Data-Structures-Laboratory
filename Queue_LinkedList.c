#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

int main()
{
    int ch,x;
    struct node *temp;

    do{
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.isEmpty 5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                temp=(struct node*)malloc(sizeof(struct node));
                printf("Enter value: ");
                scanf("%d",&x);

                temp->data=x;
                temp->next=NULL;

                if(front==NULL)
                {
                    front=rear=temp;
                }
                else
                {
                    rear->next=temp;
                    rear=temp;
                }
                break;

            case 2:
                if(front==NULL)
                    printf("Queue is Empty");
                else{
                    temp=front;
                    printf("Deleted: %d",front->data);
                    front=front->next;
                    free(temp);
                }
                break;

            case 3:
                if(front==NULL)
                    printf("Queue Empty");
                else
                    printf("Front element: %d",front->data);
                break;

            case 4:
                if(front==NULL)
                    printf("Queue is Empty");
                else
                    printf("Queue not Empty");
                break;
        }

    }while(ch!=5);

    return 0;
}