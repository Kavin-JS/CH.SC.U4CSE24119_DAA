#include <stdio.h>

int partitionFirst(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && A[i] <= pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSortFirst(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionFirst(A, low, high);
        quickSortFirst(A, low, pi - 1);
        quickSortFirst(A, pi + 1, high);
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

    quickSortFirst(A, 0, n - 1);

    printf("Sorted array (First Pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
