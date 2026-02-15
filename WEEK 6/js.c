#include <stdio.h>
#define MAX 100

// sort by profit descending
void sortByProfit(int p[], int d[], int n){
    int temp;

    for(int i = 0; i < n - 1; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(p[j] > p[max])
                max = j;
        }

        // swap profit
        temp = p[i];
        p[i] = p[max];
        p[max] = temp;

        // swap deadline
        temp = d[i];
        d[i] = d[max];
        d[max] = temp;
    }
}

// job sequencing
int jobSequencing(int p[], int d[], int n){
    sortByProfit(p, d, n);

    int maxDeadline = 0;
    for(int i = 0; i < n; i++)
        if(d[i] > maxDeadline)
            maxDeadline = d[i];

    int slot[MAX] = {0};
    int profit = 0;

    for(int i = 0; i < n; i++){
        for(int j = d[i]; j > 0; j--){
            if(slot[j] == 0){
                slot[j] = 1;
                profit += p[i];
                break;
            }
        }
    }

    return profit;
}

int main(){
    int n;
    int p[MAX], d[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter deadlines:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &d[i]);

    int ans = jobSequencing(p, d, n);
    printf("Maximum Profit = %d\n", ans);

    return 0;
}
