#include <stdio.h>

int sumofcubes(int n){
int sum = 0;
for (int i = 1; i <= n; i++) {
sum += i*i*i;
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
printf("Sum of cubes of %d natural numbers is = %d\n", in, sumofcubes(in));
return 0;
}

