#include <stdio.h>

int main() {
int in;
int prev = 1, curr = 1, next = 2;
printf("Enter N: ");
scanf("%d", &in);
if (in<=0){
printf("INVALID INPUT\n");
return 1;
}
else{
printf("%d ",prev);
for (int i = 1; i < in; i++) {
printf("%d ",curr);
prev = curr;
curr = next;
next = prev + curr;
}
}

return 0;
}

