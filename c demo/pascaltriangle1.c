#include<stdio.h>

int factorial(int numrows){
int result = 1;
for(int i = 1; i <= numrows; i++){
result *= i;
}
return result;
}

int binomcoef(int numrows, int temp){
int result2 = factorial(numrows) / (factorial(temp) * factorial(numrows - temp));
return result2;
}

int main(){
int numrows;
int temp = 0;
printf("Enter number of rows: ");
scanf("%d", &numrows);

if(numrows == 0 || numrows == 31){
    return 0;
}

printf("[");
for(int i = 0; i < numrows; i++){
    printf("[");
    for(temp = 0; temp <= i; temp++){
        int res = binomcoef(i, temp);
        printf("%d", res);
        if(temp < i){
            printf(", ");
        }
    }

    printf("]");
    if(i < numrows -1){
        printf(", ");
    }

}
printf("]");
 return 0;

}