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

void insertFirst(node **list, int element){
    node * temp = (node *)malloc(sizeof(node));
    if(temp == NULL){
        printf("Malloc was not successful.");
    } else {
        temp->data = element;
        temp->link = (*list);
        (*list) = temp;
    }
}

void display(node * list){
    while(list != NULL){
        printf("%d ", list->data);
        list = list->link;
    }
}

node * reverseList(node *list){
    node * trav = list;
    node * new = NULL;
    while(trav != NULL){
        insertFirst(&new, trav->data);
        trav = trav->link;
    }

    return new;
}

int palindrome(node *List){
    node * Rev = reverseList(List);

    while(Rev != NULL && List != NULL && Rev->data == List->data){
        Rev = Rev->link;
        List = List->link;
    }

    return (Rev == NULL && List == NULL) ? 1: 0;
}

void deleteList(node *list){
    node *trav;
    while(list != NULL){
        trav = list;
        list = list->link;
        free(trav);
    }
}

void main(){

    node * List = NULL;

    populateList(&List);

    display(List);

    int flag = palindrome(List);

    if(flag == 1){
        printf("List is a Palindrome. ");
    } else {
        printf("List is not a Palidrome. ");
    }

    deleteList(List);

}