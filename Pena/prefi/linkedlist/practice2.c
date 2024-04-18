#include <stdio.h>
#include <stdlib.h>

typedef char String[64];

typedef struct {
    String fname;
    String lname;
    char MI;
} Name;

typedef struct student{
    Name name;
    int ID;
    String Course;
    int yr;
} student;

// typedef struct node{
//     student studentrec;
//     struct node *link;
// } nodetype;

//create node with int as data so that creating functions can be easier
typedef struct node{
    int data;
    struct node *link;
} nodetype;

//nodetype * populateList();


void insertFirst(nodetype **head, int elem){
    nodetype *temp = (nodetype *) malloc(sizeof (nodetype));
    if(temp == NULL){
        printf("malloc was not successful");
        return;
    }
    temp -> link = *head;
    temp -> data = elem;
    *head = temp;
}

void insertLast(nodetype *head, int elem){
    nodetype *temp = (nodetype*) malloc(sizeof(nodetype));
    nodetype *trav = head;
    while(trav -> link != NULL){
        trav = trav->link;
    }
    temp -> link = trav ->link;
    trav -> link = temp;
    temp ->data = elem;
    
}

void insertAtPos(nodetype **head, int index, int elem) {
    nodetype *current = *head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->link;
    }
    if(current != NULL){
        insertFirst(&(current->link), elem);
    } else {
        printf("Invalid position\n");
    }
}


void display(nodetype *head){
    nodetype *trav = head;

    for(int x = 0; trav != NULL; trav = trav -> link, x++){
        printf("%d\n", trav ->data);
    }
}

void deleteElem(nodetype **head, int elem){
    nodetype *trav = *head;
    nodetype *prev = NULL;

    while(trav -> link != NULL && trav -> data != elem){
        prev = trav;
        trav = trav -> link;
    }

    if(prev == NULL){
        *head = trav -> link;
    } else {
        prev -> link = trav -> link;
    }

    free(trav);
}

void deleteOccurrences(nodetype **head, int elem){
    nodetype *trav = *head;
    nodetype *prev = NULL;
    nodetype *temp;

    while (trav -> link != NULL){
        if(trav -> data == elem){
            if(prev == NULL){
                *head = trav -> link;
            } else {
                prev -> link = trav -> link;
            }
            temp = trav;
            trav = trav -> link;
            free(temp);
        } else {
            prev = trav;
            trav = trav -> link;
        }
    }
}

void sort(nodetype **head){
    nodetype *trav;
    nodetype *smalltrav;
    nodetype *temp;
    int small;

    for(trav = *head; trav ->link != NULL; trav = trav ->link){
        nodetype *tiny = trav;
        for(smalltrav = trav -> link; smalltrav != NULL; smalltrav = smalltrav -> link){
            if(smalltrav->data < tiny->data){
                tiny = smalltrav;
            }
        }
        
        small = trav->data;
        trav->data = tiny->data;
        tiny->data = small;
    }
}

void insertsort(nodetype **head, int elem){
    nodetype *trav = *head;
    nodetype *prev = NULL;

    for(; trav != NULL && elem > trav -> data; prev = trav, trav = trav -> link){
    }

    if(trav != NULL){
        insertFirst(&(prev) -> link, elem);
    } else {
        printf("Cannot insert");
    }

}

int main(){
    nodetype *head = NULL;

    student stud[] = {{{"January", "Toledo", 'T'}, 1234, "BSCS", 1}, {{"Jomar", "Cunado", 'P'}, 1231, "BSIT", 1}, 
    {{"Kenneth", "Cahilog", 'S'}, 1232, "BSCS", 3}, {{"Jewel", "Monsalud", 'D'}, 1233, "BSIT", 1}};

    insertFirst(&head, 4);
    insertFirst(&head, 8);
    insertFirst(&head, 3);
    insertFirst(&head, 10);
    insertFirst(&head, 11);
    insertFirst(&head, 2);
    insertFirst(&head, 1);

    insertAtPos(&head, 4, 6); 

    insertLast(head, 5);

    display(head);

    //deleteElem(&head, 1);

    //deleteOccurrences(&head, 3);

    sort(&head);

    printf("version 2: \n");

    display(head);

    insertsort(&head, 7);

    printf("version 3: \n");

    display(head);

    //https://leetcode.com/tag/linked-list/

    free(head);
}