#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 50
typedef struct
{
    struct StudentName
    {
        char FName[16];
        char LName[24];
        char MI;
    } name;
    int ID;
    char Course[8];
    int Yr;
    
} StudType;

typedef struct 
{
    StudType stud[SIZE];
    int count;
} StudList;

void getStudent(StudType *stud);
void displayStudent(StudType stud);
void displayList(StudList *L);
void initializeList(StudList *L);
void populateList(StudList *L);
bool findElem(StudList *L, int elem);
void addStudent(StudList *L);

//challenge functions nag ai nalang si bai sa uban ky katolgon na sorry so much
void insertStudent(StudList *L);
void deleteStudent(StudList *L, int elem);
void sortList(StudList *L);
void insertSorted(StudList *L);

void main(){
    StudList List;

    initializeList(&List);
    populateList(&List);

    //printf("1: Display 2: Add 3: Find");

    displayList(&List);

}

void initializeList(StudList *L)
{
    L -> count = 0;
}

void populateList(StudList *L)
{
    int x, y;
    printf("How many students will you add? ");
    scanf("%d", &x);

    for(y = 0; y < x; y++)
    {
        addStudent(L);
    }
}

bool findElem(StudList *L, int elem)
{
    int x;
    for(x = 0; x < L->count && L->stud[x].ID != elem; x++){
    }
    if (x < L->count)
    {
        return true;
    } else
    {
        return false;
    }
}

void getStudent(StudType *stud)
{
        printf("Enter First Name: ");
        scanf(" %s", stud->name.FName);
        printf("Enter Middle Initial: ");
        scanf(" %c", &stud->name.MI);
        printf("Enter Last Name: ");
        scanf(" %s", stud->name.LName);
        printf("Enter Student ID: ");
        scanf(" %d", &stud->ID);
        printf("Enter Course: ");
        scanf(" %s", stud->Course);
        printf("Enter Year Level: ");
        scanf(" %d\n", &stud->Yr);
}

void addStudent(StudList *L)
{
    if (L->count < SIZE)
    {
        getStudent(&(L->stud[L->count]));
        L->count++;
    } else {
        printf("List is full cannot add more students.");
    }
}

void insertStudent(StudList *L)
{
    // if(L->count < SIZE)
    // {
    //     //should use memmove daw
    //     //memmove(&L->stud[1], &L->stud[0], sizeof(StudType) * L->count);
    //     memcpy(L->stud[1], L->stud[0], sizeof(StudType) * L->count + 1);

    //     getStudent(&(L->stud[0]));

    //     L->count++;
    // }

    if(L->count < SIZE)
    {
        // Shift elements to the right
        for (int i = L->count; i > 0; i--)
        {
            L->stud[i] = L->stud[i - 1];
        }
        getStudent(&(L->stud[0])); // Insert the new student at index 0
        L->count++;
    }
}

void deleteStudent(StudList *L, int elem)
{
    // int x;
    // for(x = 0; x < L->count && L->stud[x].ID != elem; x++)
    // {
    // }
    // //should use memmove daw
    // //memmove(&L->stud[x], &L->stud[x + 1], sizeof(StudType) * (L->count - x - 1));
    // memccpy(L->stud[x], L->stud[x + 1], sizeof(StudType) * L->count - 1);

    int index;
    for(index = 0; index < L->count; index++)
    {
        if (L->stud[index].ID == elem)
        {
            // Shift elements to the left starting from the found index
            for (int i = index; i < L->count - 1; i++)
            {
                L->stud[i] = L->stud[i + 1];
            }
            L->count--;
            break;
        }
    }
}

void sortList(StudList *L)
{
    int x, y;
    for (x = 0; x < L->count-1; x++)
    {      
        for (y = 0; y < L->count-x-1; y++)
        { 
            if (L->stud[y].ID > L->stud[y+1].ID)
            {
                // Swap the students
                //make this into a function nya kay grabe ky sya ka nested
                StudType temp = L->stud[y];
                L->stud[y] = L->stud[y+1];
                L->stud[y+1] = temp;
            }
        }
    }
}

void insertSorted(StudList *L)
{
    if (L->count >= SIZE)
    {
        printf("List is full, cannot add more students.\n");
        return;
    }

    // Get the new student details
    StudType newStudent;
    getStudent(&newStudent);

    // Find the position to insert the new student
    int i;
    for (i = 0; i < L->count; i++)
    {
        if (L->stud[i].ID > newStudent.ID)
        {
            break;
        }
    }

    // Shift the elements to the right of the position
    for (int j = L->count; j > i; j--)
    {
        L->stud[j] = L->stud[j - 1];
    }
    //or use memcpy or call a memcpy/memmove function for shifting students to add new ones

    // Insert the new student
    L->stud[i] = newStudent;
    L->count++;
}


void displayStudent(StudType stud)
{
    printf("Student\nName: ");
    printf("%s %c %s\n", stud.name.FName,stud.name.MI, stud.name.LName);
    printf("ID: %d\n", stud.ID);
    printf("Course: %s\n", stud.Course);
    printf("Year Level: %d\n", stud.Yr);
}

void displayList(StudList *L)
{
    int x;
    for(x = 0; x < L->count; x++){
        displayStudent(L->stud[x]);
    }
}