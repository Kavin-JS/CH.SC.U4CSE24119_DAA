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
    int arr[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quickSortFirst(arr, 0, n - 1);

    printf("\n\nSorted Array (First Pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
