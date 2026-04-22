#include <stdio.h>

int main()
{
    int r1, c1, r2, c2, choice;
    int a[10][10], b[10][10], result[10][10];

    printf("Select Operation\n");
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Transpose of Matrix\n");
    printf("5. Identity Matrix\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1 || choice == 2)
    {
        printf("Enter rows and columns: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter first matrix:\n");
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                scanf("%d", &a[i][j]);

        printf("Enter second matrix:\n");
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                scanf("%d", &b[i][j]);

        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                result[i][j] = (choice == 1) ? a[i][j] + b[i][j] : a[i][j] - b[i][j];

        printf("Result:\n");
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c1; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }

    else if(choice == 3)
    {
        printf("Enter rows and columns of first matrix: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter rows and columns of second matrix: ");
        scanf("%d%d", &r2, &c2);

        if(c1 != r2)
        {
            printf("Multiplication not possible");
            return 0;
        }

        printf("Enter first matrix:\n");
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                scanf("%d", &a[i][j]);

        printf("Enter second matrix:\n");
        for(int i = 0; i < r2; i++)
            for(int j = 0; j < c2; j++)
                scanf("%d", &b[i][j]);

        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c2; j++)
            {
                result[i][j] = 0;
                for(int k = 0; k < c1; k++)
                    result[i][j] += a[i][k] * b[k][j];
            }

        printf("Result:\n");
        for(int i = 0; i < r1; i++)
        {
            for(int j = 0; j < c2; j++)
                printf("%d ", result[i][j]);
            printf("\n");
        }
    }

    else if(choice == 4)
    {
        printf("Enter rows and columns: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter matrix:\n");
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                scanf("%d", &a[i][j]);

        printf("Transpose:\n");
        for(int j = 0; j < c1; j++)
        {
            for(int i = 0; i < r1; i++)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }

    else if(choice == 5)
    {
        int n;
        printf("Enter order of matrix: ");
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }

    else
    {
        printf("Invalid Choice");
    }

    return 0;
}
