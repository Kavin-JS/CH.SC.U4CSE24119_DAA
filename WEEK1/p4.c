#include <stdio.h>

int facto(int n){
if (n <= 0){
return 1;
}
else{
return n * facto(n-1);
}
}

int main() {
int in;
printf("Enter N: ");
scanf("%d", &in);
if (in<=0){
printf("INVALID INPUT\n");
return 1;
}
printf("Factorial of %d is = %d\n", in, facto(in));
return 0;
}

