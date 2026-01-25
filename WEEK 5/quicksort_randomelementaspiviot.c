#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int partitionRandom(int A[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);

    int temp = A[randomIndex];
    A[randomIndex] = A[high];
    A[high] = temp;

    return partitionLast(A, low, high);
}

void quickSortRandom(int A[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionRandom(A, low, high);

        quickSortRandom(A, low, pi - 1);
        quickSortRandom(A, pi + 1, high);
    }
}

int main()
{
    srand(time(0));

    int arr[] = {157,110,147,122,111,149,151,141,123,112,117,133};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quickSortRandom(arr, 0, n - 1);

    printf("\n\nSorted Array (Random Pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
