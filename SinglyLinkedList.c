#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin(int x)
{
    struct node *temp;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = head;

    head = temp;
}

void insert_end(int x)
{
    struct node *temp,*ptr;

    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = x;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    ptr = head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void delete_begin()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is Empty");
        return;
    }

    temp = head;

    head = head->next;

    printf("Deleted element: %d",temp->data);

    free(temp);
}

void display()
{
    struct node *ptr;

    ptr = head;

    if(ptr == NULL)
    {
        printf("List is Empty");
        return;
    }

    printf("Linked List: ");

    while(ptr != NULL)
    {
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

int main()
{
    int ch,x;

    do
    {
        printf("\n1.Insert at Beginning");
        printf("\n2.Insert at End");
        printf("\n3.Delete from Beginning");
        printf("\n4.Display");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                insert_begin(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d",&x);
                insert_end(x);
                break;

            case 3:
                delete_begin();
                break;

            case 4:
                display();
                break;
        }

    }while(ch != 5);

    return 0;
}