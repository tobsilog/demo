#include<stdio.h>

int factorial(int numrows){
int result = 1;
for(int i = 1; i <= numrows; i++){
result *= i;
}
return result;
}

int binomcoef(int row, int element){
int result2 = factorial(row) / (factorial(element) * factorial(row - element));
return result2;
}

int main(){
int numrows;

printf("Enter number of rows: ");
scanf("%d", &numrows);

//int i;

if(numrows == 0 || numrows == 31){
    return 0;
}

//printf("[");

for(int i = 0; i < numrows; i++){

    for ( int j = 0; j <= numrows - 1 - i; j++){
        printf(" ");
    }
    printf("[");
    for(int temp = 0; temp <= i; temp++){
        int res = binomcoef(i, temp);
        printf("%d", res);
        if (temp < i ) {

            printf(",");
        }

    }
    printf("]");

    /*if (i < numrows - 1) {
        printf(", ");
    }*/
    printf("\n");
}
//printf("]");

return 0;

}