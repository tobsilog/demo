int arr [] = {1, 2, 3};

node * List = NULL;

node *temp = (node*)malloc(sizeof(node));
node **trav = &head;
temp->data = data;
temp-> = (*trav);
(*trav) = temp;

typedef int Arr[20];

array[0] = 10;

//Traversal is needed
while(trav != NULL){}

//Copy
insertSort(array);
//Address
insertSort(array);

//Copy
insertSort(List);
//Address
insertSort(&List);

void insertSort(int array[]) 
void insertSort(int *array)
int * insertSort(int array)

void traverse(node *list)
void insert(node **list)
node * removeoccurrence(node *list)

//array cannot be on the left side of the 
//assignment because the name of the array 
//is a pointer to the first element

//The new list will only be pointing to the 
//first element of the first list same as the 
//head of said list, the list will not be 
//copied to the new list

for(i = 0; i < size && array[i] != element; i++){}

//PN
for(trav = head; trav != NULL && trav->data != element; trav = trav->link){}
prev->link = trav->link;
free(trav);
trav = prev->link;
//PPN
for(trav = &head; (*trav) != NULL (*trav)->data != element; trav = &(*trav)->link){}

//local array cannot be returned to the main function 
//and must be dynamically allocated

return newList;

for (i = 0; i < *size && arr[i] == element; i++) {}

    if (i < *size) {
        (*size)--;
        for (int j = i; j < *size; j++) {
            arr[j] = arr[j + 1];
        }
    } else {
        printf("Element not found in the array.\n");
    }

    for (int i = *size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    (*size)++;