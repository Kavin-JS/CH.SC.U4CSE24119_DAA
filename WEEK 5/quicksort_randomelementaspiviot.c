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
    int n;

    srand(time(0));

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    quickSortRandom(A, 0, n - 1);

    printf("Sorted array (Random Pivot):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
