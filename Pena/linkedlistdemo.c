#include <stdio.h>

typedef struct cell {
    char data;
    struct cell *link;
} celltype, *LIST;

void insertLast(LIST *L, char element);

void main() {
    LIST L;
    L = (LIST) malloc(sizeof(celltype));
    LIST temp;
    for(temp = L; temp != NULL; temp = temp->link) 
    {
        scanf("%c", temp->data);
    }

    insertLast(L, 'Y');
}

void insertLast(LIST *L, char element)
{
    LIST temp;
    temp = (LIST) malloc(sizeof(celltype));
    temp ->data = 'C';
    temp ->link = L;
    L = temp;
}

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct cell {
//     char data;
//     struct cell *link;
// } celltype, *LIST;

// void insertLast(LIST *L, char element);

// int main() {
//     LIST L = NULL;
//     char ch;
//     while(scanf(" %c", &ch) == 1) {
//         insertLast(&L, ch);
//     }

//     insertLast(&L, 'Y');
//     return 0;
// }

// void insertLast(LIST *L, char element)
// {
//     LIST newNode = (LIST) malloc(sizeof(celltype));
//     newNode->data = element;
//     newNode->link = NULL;

//     if (*L == NULL) {
//         *L = newNode;
//     } else {
//         LIST temp = *L;
//         while (temp->link != NULL) {
//             temp = temp->link;
//         }
//         temp->link = newNode;
//     }
// }

