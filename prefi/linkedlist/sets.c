#include <stdio.h>
#include <stdlib.h>

typedef struct set
{
   int data;
   struct set * link;
}set;

// void insertFirst(set **A, int data){
//     set * temp = (set *) malloc(sizeof(set));
//     if(temp != NULL){
//         temp->data = data;
//         temp ->link = (*A);
//         (*A) = temp;
//     } else {
//         printf("Malloc was not successful");
//     }
// }

void insertLast(set **A, int data){
    set *temp = (set *) malloc(sizeof(set));
    set **trav;
    if(temp == NULL){
        printf("Malloc was not successful. ");
    } else {
        for(trav = A; (*trav) != NULL; trav = &(*trav)->link){
        }
        temp->link = NULL;
        temp->data = data;
        (*trav) = temp;
    }
    
}

void populateList(set **A){
    int elemctr, data;
    printf("How many elements: ");
    scanf("%d", &elemctr);

    for(int x = 0; x < elemctr; x++){
        scanf("%d", &data);
        insertLast(A, data);
    }
}

void display(set *A){
    while(A != NULL){
        printf("%d", A->data);
        A = A->link;
    }
}

set * unionSet(set *A, set *B){
    set *C = NULL;
    set *Aptr = A, *Bptr = B, **Cptr = &C;
    while(Aptr != NULL && Bptr != NULL){
        if(Aptr->data < Bptr->data){
            insertLast(Cptr, Aptr->data);
            Aptr = Aptr->link;
        } else if (Bptr->data < Aptr->data){
            insertLast(Cptr, Bptr->data);
            Bptr = Bptr->link;
        } else if(Aptr->data==Bptr->data){
            insertLast(Cptr, Aptr->data);
            Bptr = Bptr->link;
            Aptr = Aptr->link;
        }
        Cptr = &(*Cptr)->link;
    }

    if(Aptr != NULL){
        while(Aptr != NULL){
            insertLast(Cptr, Aptr->data);
            Aptr = Aptr->link;
        }
    } else if(Bptr != NULL){
        while(Bptr != NULL){
            insertLast(Cptr, Bptr->data);
            Bptr = Bptr->link;
        }
    }

    return C;
}

set * unionUnsorted(set *A, set * B){
    set * C = NULL;
    set *Aptr = A, *Bptr = B, **Cptr = &C;

    while(Aptr != NULL){
        insertLast(&C, Aptr->data);
        Aptr = Aptr->link;
    }

    while(Bptr != NULL){
        Aptr = A;
        while(Aptr != NULL && Bptr->data != Aptr->data){
            Aptr = Aptr->link;
        }
        if(Aptr == NULL){
            insertLast(&C, Bptr->data);
        }
        Bptr = Bptr->link;
    }

    return C;
}

void deleteList(set** head_ref) {
    /* deref head_ref to get the real head */
    set* current = *head_ref;
    set* next;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }
    
    /* deref head_ref to affect the real head back in the caller */
    *head_ref = NULL;
}

void main(){
    set *A = NULL;
    set *B = NULL;

    populateList(&A);
    printf("\nSet A: ");
    display(A);
    populateList(&B);
    printf("\nSet B: ");
    display(B);
    set *C = unionUnsorted(A, B);
    printf("\nSet C Union of A B: ");
    display(C);

    deleteList(&A);
    deleteList(&B);
    deleteList(&C);
    
}