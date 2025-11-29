#include <stdio.h>

int main() {
int r=3,c=3;
int mat[r][c];

for (int i = 0; i < r; i++){
printf("Enter Row %d Inputs : ",i + 1);
for (int j = 0; j < c; j++){
int in = 0;
scanf("%d",&in);
mat[i][j] = in;
}
}

for (int i = 0; i < r; i++){
printf("\n");
for (int j = 0; j < c; j++){
printf("%d ", mat[j][i]);
}
}
printf("\n");


return 0;
}

