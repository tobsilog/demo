#include <stdio.h>
#include <stdlib.h>

int * multFrac(int A[], int B[]){
    A[0] *=  B[0];
    A[1] *= B[1];

    int *array = (int *) malloc(2*sizeof(int));

    array[0] = A[0];
    array[1] = A[1];

    return array;
}

int * add(int A[], int B[]){
    int product = A[1] * B[1];
    
    while(A[1] != B[1]){
        if(A[1]>B[1]){
            A[1]-=B[1];
        } else {
            B[1]-=A[1];
        }
    }

    product/=A[1];
    //A[1] *= product;
    A[0] += B[0];

    int * array = (int *) malloc(2*sizeof(int));

    array[0] = A[0];
    array[1] = A[1];

    return array;

}

void getgcf(int A[]){
    int A2[] = {[0] = A[0], [1] = A[1] };
    while(A2[0] != A2[1]){
        if(A2[0] > A2[1]){
            A2[0] -= A2[1];
        } else {
            A2[1] -= A2[0];
        }
    }
    A[0] /= A2[0];
    A[1] /= A2[0];

    printf("\nGCF %d", A[0]);
}

int main(){
    int A[2];
    // =  {1,2};
    int B[2]; 
    //= {2,3};

    scanf("%d %d", &A[0], &A[1]);
    scanf("%d %d", &B[0], &B[1]);


    int * array2 = multFrac(A, B);

    printf("Product: %d %d", A[0], A[1]);

    int * array3 = add(A, B);

    printf("\nSum: %d %d", A[0], A[1]);

    //getgcf(A);

    free(array2);

    free(array3);
}