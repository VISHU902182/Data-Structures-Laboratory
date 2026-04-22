#include <stdio.h>

int main() {
    int arr[5];
    int choice, i, sum = 0, max, min, index, value;
    int created = 0;

    while (1) {
        printf("\n===== Menu =====\n");
        printf("1. Create array of 5 elements\n");
        printf("2. Display elements\n");
        printf("3. Max value in array\n");
        printf("4. Min value in array\n");
        printf("5. Sum of all elements\n");
        printf("6. Update array element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter 5 elements:\n");
                for (i = 0; i < 5; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                created = 1;
                printf("Array created successfully!\n");
                break;

            case 2:
                if (!created) {
                    printf("Create array first!\n");
                    break;
                }
                printf("Array elements: ");
                for (i = 0; i < 5; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                if (!created) {
                    printf("Create array first!\n");
                    break;
                }
                max = arr[0];
                for (i = 1; i < 5; i++) {
                    if (arr[i] > max)
                        max = arr[i];
                }
                printf("Maximum value: %d\n", max);
                break;

            case 4:
                if (!created) {
                    printf("Create array first!\n");
                    break;
                }
                min = arr[0];
                for (i = 1; i < 5; i++) {
                    if (arr[i] < min)
                        min = arr[i];
                }
                printf("Minimum value: %d\n", min);
                break;

            case 5:
                if (!created) {
                    printf("Create array first!\n");
                    break;
                }
                sum = 0;
                for (i = 0; i < 5; i++) {
                    sum += arr[i];
                }
                printf("Sum of all elements: %d\n", sum);
                break;

            case 6:
                if (!created) {
                    printf("Create array first!\n");
                    break;
                }
                printf("Enter index (0-4): ");
                scanf("%d", &index);
                if (index < 0 || index >= 5) {
                    printf("Invalid index!\n");
                    break;
                }
                printf("Enter new value: ");
                scanf("%d", &value);
                arr[index] = value;
                printf("Element updated successfully!\n");
                break;

            case 7:
                printf("Exiting program!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}