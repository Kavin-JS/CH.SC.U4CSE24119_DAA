#include <stdio.h>

int sumofsquares(int n){
int sum = 0;
for (int i = 1; i <= n; i++) {
sum += i*i;
}
return sum;
}

int main() {
int in;
printf("Enter N: ");
scanf("%d", &in);
if (in<=0){
printf("INVALID INPUT\n");
return 1;
}
printf("Sum of squares of %d natural numbers is = %d\n", in, sumofsquares(in));
return 0;
}

