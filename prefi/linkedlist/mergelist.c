#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

void insertLast(node **list, int elem){
    node * temp = (node *) malloc(sizeof(node));
    node **current;

    if(temp == NULL){
        printf("Malloc was not successful");
    } else{
        for(current = list; (*current) != NULL; current = &(*current)->link){}
        temp->data = elem;
        temp->link = NULL;
        (*current) = temp;
    }

}

void populateList(node **list){
    int ctr, element;
    printf("How many elements? ");
    scanf("%d", &ctr);
    while(ctr != 0){
        scanf("%d", &element);
        insertLast(list, element);
        ctr--;
    }
}

void display(node * list){
    while(list != NULL){
        printf("%d ", list->data);
        list = list->link;
    }
}

void deleteList(node *list){
    node *trav;
    while(list != NULL){
        trav = list;
        list = list->link;
        free(trav);
    }
}

node * mergeLists(node **A, node **B){
    node * newList = NULL;
    node **C = &newList;
    while((*A) != NULL && (*B) != NULL){

        if((*A)->data <= (*B)->data){
            (*C) = (*A);
            *A = (*A)->link;
        } else {
            (*C) = (*B);
            *B = (*B)->link;
        }
        
        C = &(*C)->link;
    }

    if((*A) != NULL){
        (*C) = (*A);
    } else {
        (*C) = (*B);
    }

    return newList;
}

void main(){
    node *List = NULL;
    node *Second = NULL;

    populateList(&List);
    populateList(&Second);

    printf("First List: ");
    display(List);
    printf("\nSecond List: ");
    display(Second);

    node * merged = mergeLists(&List, &Second);

    printf("\nMerged List: ");
    display(merged);

    deleteList(merged);

}