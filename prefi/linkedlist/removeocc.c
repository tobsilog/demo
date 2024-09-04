#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node * removemultiples(node ** list){
    node * new = NULL;
    node * temp;
    node ** trav = list;
    while((*trav) != NULL){
        if((*trav)->data % 5 == 0){
            temp = (*trav);
            (*trav) = temp ->link;
            temp->link = new;
            new = temp;
        } else {
            trav = &(*trav)->link;
        }
    }
    return new;
}

void display(node *A){
    while(A != NULL){
        printf("%d ", A->data);
        A = A->link;
    }
}

void insertLast(node **A, int data){
    node *temp = (node *) malloc(sizeof(node));
    node **trav;
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

void populate(node **List){
    int ctr, element;
    printf("How many elements? ");
    scanf("%d", &ctr);

    while(ctr != 0){
        scanf("%d", &element);
        insertLast(List, element);
        ctr--;
    }
}

void deleteList(node **list){
    node *current = (*list);

    while(current != NULL){
        (*list) = (*list)->link;
        free(current);
        current = (*list);
    }

    (*list) = NULL;
}

void main() {
    node * list = NULL;

    populate(&list);

    printf("Original List: \n");
    display(list);
    printf("\n");

    node * removed = removemultiples(&list);

    printf("List after removing multiple of 5: \n");
    display(list);
    printf("\n");

    deleteList(&list);
}