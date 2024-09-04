#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[64];

typedef struct {
    String fname;
    String lname;
    char MI;
} Name;

typedef struct student{
    Name name;
    int ID;
    char Course[8];
    int yr;
} student;

typedef struct node{
    student studentrec;
    struct node *link;
} nodetype;

//create node with int as data so that creating functions can be easier
// typedef struct node{
//     int data;
//     struct node *link;
// } nodetype;

//nodetype * populateList();

void insertFirst(nodetype **head, student stud){
    nodetype *temp = (nodetype *) malloc(sizeof (nodetype));
    if(temp == NULL){
        printf("malloc was not successful");
        return;
    }
    temp -> link = *head;
    temp -> studentrec = stud;
    *head = temp;
}

void insertLast(nodetype *head, student stud){
    nodetype *temp = (nodetype*) malloc(sizeof(nodetype));
    nodetype *trav = head;
    while(trav -> link != NULL){
        trav = trav->link;
    }
    temp -> link = trav ->link;
    trav -> link = temp;
    temp ->studentrec = stud;
    
}

void insertAtPos(nodetype **head, int index, student stud) {
    nodetype *current = *head;
    for (int i = 0; i < index - 1 && current != NULL; i++) {
        current = current->link;
    }
    if(current != NULL){
        insertFirst(&(current->link), stud);
    } else {
        printf("Invalid position\n");
    }
}

void Displayname(Name pname){
    printf("\n%s, %s %c", pname.lname, pname.fname, pname.MI);
}

void display(nodetype *head){
    nodetype *trav = head;
    printf("Student List: \n");
    for(int x = 0; trav != NULL; trav = trav -> link, x++){
        Displayname(trav->studentrec.name);
        printf("\nID: %d", trav->studentrec.ID);
        printf("\nCourse: %s", trav->studentrec.Course);
        printf("\nYear: %d", trav->studentrec.yr);
    }
}


student deleteElem(nodetype **head, char name[]){
    nodetype *trav = *head;
    nodetype *prev = NULL;

    while(trav -> link != NULL && (strcmp(trav->studentrec.name.fname, name) != 0) ){
        prev = trav;
        trav = trav -> link;
    }

    if(prev == NULL){
        *head = trav -> link;
    } else if(trav == NULL){
        printf("Student not found.");
    } else {
        prev -> link = trav -> link;
    }

    return trav->studentrec;

    free(trav);
}

void deleteOccurrences(nodetype **head, char courseremv[]){
    nodetype *trav = *head;
    nodetype *prev = NULL;
    nodetype *temp;

    while (trav != NULL){
        if(strcmp(trav->studentrec.Course, courseremv) == 0){
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
    student small;

    for(trav = *head; trav ->link != NULL; trav = trav ->link){
        nodetype *tiny = trav;
        for(smalltrav = trav -> link; smalltrav != NULL; smalltrav = smalltrav -> link){
            if(strcmp(tiny->studentrec.name.lname, smalltrav->studentrec.name.lname) > 0){
                tiny = smalltrav;
            }
        }
        
        small = trav->studentrec;
        trav->studentrec = tiny->studentrec;
        tiny->studentrec = small;
    }
}

void insertsort(nodetype **head, student stud){
    nodetype *trav = *head;
    nodetype *prev = NULL;

    for(; trav != NULL && (strcmp(trav->studentrec.name.lname, stud.name.lname) < 0); trav = trav -> link){
    }

    if(trav != NULL){
        insertFirst(&(trav)->link, stud);
    } else {
        printf("Cannot insert");
    }

}

void deleteList(nodetype** head_ref) {
    /* deref head_ref to get the real head */
    nodetype* current = *head_ref;
    nodetype* next;

    while (current != NULL) {
        next = current->link;
        free(current);
        current = next;
    }
    
    /* deref head_ref to affect the real head back in the caller */
    *head_ref = NULL;
}


int main(){
    nodetype *head = NULL;

    student stud[] = {{{"January", "Toledo", 'T'}, 1234, "BSCS", 1}, {{"Jomar", "Cunado", 'P'}, 1231, "BSIT", 1}, 
    {{"Kenneth", "Cahilog", 'S'}, 1232, "BSCS", 3}, {{"Jewel", "Monsalud", 'D'}, 1233, "BSIT", 1}};

    student newstudent = {{"Cheska", "Ouano", 'E'}, 1235, "BSIT", 2};

    student laststud = {{"Louis", "Ouano", 'F'}, 1236, "BSCS", 1};

    insertFirst(&head, stud[0]);
    insertFirst(&head, stud[1]);
    insertFirst(&head, stud[2]);
    insertFirst(&head, stud[3]);

    insertAtPos(&head, 2, newstudent); 

    insertLast(head, laststud);

    printf("Version 1: ");

    display(head);

    student removed = deleteElem(&head, "Cheska");

    printf("\nSuccessfully removed: %s", removed.name.fname);

    //deleteOccurrences(&head, "BSCS");

    printf("\nversion 2: \n");

    display(head);

    sort(&head);

    printf("\nversion 3: \n");

    display(head);

    insertsort(&head, newstudent);

    printf("\n version 4: \n");
    
    display(head);

    //https://leetcode.com/tag/linked-list/

    deleteList(&head);

    //free(head);
}