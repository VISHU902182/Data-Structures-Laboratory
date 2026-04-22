#include <stdio.h>

int main()
{
    int n, i, arr[100], choice, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSelect Searching Method\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter element to search: ");
    scanf("%d", &key);

    if(choice == 1)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(arr[i] == key)
            {
                printf("Element found at position %d", i + 1);
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            printf("Element not found");
        }
    }

    else if(choice == 2)
    {
        int j, temp;

        for(i = 0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        int low = 0;
        int high = n - 1;
        int found = 0;

        while(low <= high)
        {
            int mid = (low + high) / 2;

            if(arr[mid] == key)
            {
                printf("Element found at position %d", mid + 1);
                found = 1;
                break;
            }
            else if(arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(found == 0)
        {
            printf("Element not found");
        }
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}
