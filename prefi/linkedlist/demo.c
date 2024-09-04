#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node{
    int data;
    struct node *next;
};

struct node *makePopulateList();
struct node *makePopulateList(){
    struct node *head = (struct node *) malloc( sizeof(struct node));
    head->data = 1;
    struct node*temp;
    //while(temp->next != NULL)
    int x;
    int element = 0;
    for(x = 0; x < MAX ; x++)
    {
        // temp = head;
        // temp->data = ++element;
        // temp = temp->next;
        // if(x == MAX){
        //     temp->next = NULL;
        // }
    }
    return head;
}
// void display(struct node head);
// struct node *find(struct node head);
// void deleteList(struct node *head); //not sure if pass by address or copy basta e free ang each node sa list
// void insertRear(struct node head, int element);
// void insertFirst(struct node *head, int element);
// void insertPosition(struct node *head, int element, int index);
// void deleteElem(struct node *head, int element);
// void deleteOccurence(struct node *head, int element);
// struct node *deleteElem(struct node *head, int element);//can also be called extract element
// struct node *deleteOccurence(struct node *head, int element);//not sorted and sorted version
// void sort(struct node *head);
// void insertSorted(struct node *head, int element);
// void displayOccurence(struct node head, int element );
// void reverse(struct node *head);
// void deleteSecndOccur(struct node head);
// void findMedian(struct node head);
// struct node *findMedian(struct node head); //either e return as copy from list or e extract
// //katong tax bracket problem sa midterms practical but linked list version
// void mergeLists(struct node *head1, struct node *head2);
// //delete node function na data is divisible by 2
// void sortEvenOdd(struct node *head);
//binary search sa linked list?


void main(){
    struct node *head = makePopulateList();

    printf("%d", head->data);

    free(head);

}

