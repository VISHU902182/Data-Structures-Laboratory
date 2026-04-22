#include <stdio.h>

int main()
{
    int n, arr[100], choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSelect Sorting Method\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Counting Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < n-i-1; j++)
            {
                if(arr[j] > arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    else if(choice == 2)
    {
        for(int i = 0; i < n-1; i++)
        {
            int min = i;

            for(int j = i+1; j < n; j++)
            {
                if(arr[j] < arr[min])
                {
                    min = j;
                }
            }

            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    else if(choice == 3)
    {
        for(int i = 1; i < n; i++)
        {
            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key)
            {
                arr[j+1] = arr[j];
                j--;
            }

            arr[j+1] = key;
        }
    }

    else if(choice == 4)
    {
        int max = arr[0];

        for(int i = 1; i < n; i++)
        {
            if(arr[i] > max)
                max = arr[i];
        }

        int count[100] = {0};

        for(int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }

        int index = 0;

        for(int i = 0; i <= max; i++)
        {
            while(count[i] > 0)
            {
                arr[index] = i;
                index++;
                count[i]--;
            }
        }
    }

    else
    {
        printf("Invalid Choice");
        return 0;
    }

    printf("Sorted Array:\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
