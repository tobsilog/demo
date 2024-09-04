#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * link;
} node;

void insertLast(node **List, int element){
    node * temp = (node *) malloc(sizeof(node));
    if(temp == NULL){
        printf("Malloc was not successful.");
    } else {
        temp->data = element;
        node ** trav = &List;
        for(;(*trav) != NULL; trav = &(*trav)->link){}
        temp->link = NULL;
        (*trav) = temp;
    }
}

void populateList(node **List){
    int ctr, element;
    printf("How many elements? ");
    scanf("%d", &ctr);
    while(ctr != 0){
        scanf("%d", &element);
        insertLast(List, element);
        ctr--;
    }
}

void display(node * List){
    while(list != NULL){
        printf("%d ", List->data);
        List = List->link;
    }
}

// void sortListbyNode(node **List){
//     node *A, *B;

//     node * small;
//     for(A = *List; A != NULL; A = A->link){
//         small = A;
//         for(B = A->link; B != NULL; B = B->link){
//             if(small->data > B->data){
//                 small = B;
//             }
//         }
//     }
// } I GIVE UP NAH F THIS SHIT DI MANI NEED

void deleteList(node **List){
    node *current = (*list);

    while(current != NULL){
        (*list) = (*list)->link;
        free(current);
        current = (*list);
    }

    (*list) = NULL;
}

void main(){
    node * List = NULL;

    populateList(&List);

    printf("Original version of List: ");
    display(List);




    deleteList(&List);
}