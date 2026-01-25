#include <stdio.h>

int partitionLast(int A[], int low, int high)
{
    int pivot = A[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[high];
    A[high] = temp;

    return i + 1;
}

void quickSortLast(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionLast(A, low, high);
        quickSortLast(A, low, pi - 1);
        quickSortLast(A, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quickSortLast(A, 0, n - 1);

    printf("Sorted array (Last Pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
