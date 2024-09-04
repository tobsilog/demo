#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
void printThis(struct node *trav){
    while (trav->next != NULL){
        trav = trav->next;
        printf("%d, ",trav->data);
    }
}

void insertrear(struct node *trav, int newData){
    while (trav->next != NULL){
        trav = trav->next;
    }
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->data = newData;
    trav->next = temp;
    temp->next = NULL;

    // trav->next = (struct node*) malloc(sizeof(struct node));
    // trav = trav->next;
    // trav->data = newData;
    // trav->next = NULL;
}
void insertAtStart(struct node *trav, int newData){
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->next = trav->next;
    temp->data = newData;
    trav->next = temp;
}

void insertAt(struct node *trav, int newData, int index){
    
    for (int i = 0; i < index; ++i){
        if (trav->next == NULL){
            struct node *temp1 = (struct node*) malloc(sizeof(struct node));
            temp1->next = NULL;
            temp1->data = 0;
            trav->next = temp1;
        }
        trav = trav->next;
        
        
    }
    struct node *temp = (struct node*) malloc(sizeof(struct node));
    temp->next = trav->next;
    temp->data = newData;
    trav->next = temp;
}
void deleteAllOccurence(struct node *trav, int to_delete){
    while (trav->next != NULL){
        if (trav->next->data == to_delete){
            trav->next = trav->next->next;
        } else{
            trav = trav->next;
        }
    }
}

int main(){
    struct node *head = (struct node*) malloc(sizeof(struct node));
    // struct node *one = (struct node*) malloc(sizeof(struct node));
    // one->data = 1;
    // head->next = one;

    // struct node *two = (struct node*) malloc(sizeof(struct node));
    // two->data = 2;
    // one->next = two;

    // struct node *tree = (struct node*) malloc(sizeof(struct node));
    // tree->data = 3;
    // two->next = tree;
    // tree->next = NULL;
    insertrear(head,69);
    insertrear(head,79);
    insertrear(head,89);
    insertrear(head,89);
    insertrear(head,89);
    insertrear(head,89);
    insertrear(head,89);
    insertAtStart(head,100);
    insertAt(head,6969,7);
    deleteAllOccurence(head,89);
    printThis(head);

    return 0;
    
}