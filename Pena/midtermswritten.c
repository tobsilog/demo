#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];

typedef enum {true, false} bool;

typedef struct {
    string fname;
    string mname;
    string lname;
}nametype;

typedef struct {
    int month;
    int day;
    int year;
} dateofbirth;

typedef struct {
    string id;
    nametype name;
    int age;
    dateofbirth DoB;
    bool gender;
} Class;

typedef struct {
    Class *List; //dynalically allocated array;
    int ctr;
    int max;
} ClassList, *ClassListPtr;



ClassList removeAll(ClassList *A, int month, bool genremv);
//remove all females and born in march 3 and return the removed people
//data {"2013002061", {patricia, elato, monserate}, 17, {5, 12, 1999}, false}
//{"2013002062", {chris, mas gwapo, sabandal}, 18, {8, 9, 1999}, true}
//{"2013002063", {christie, gwapa, cobar}, 22, {3, 10, 1999}, false}
//{"2013002064", {godwin, granito, maderazo}, 20, {3, 4, 1999}, true}
//{"2013002065", {chelsea, rea, pepito}, 21, {3, 16, 1999}, false}

void Initialize(ClassList *L);

int main() {

    ClassList CS;
    CS.List = (Class *) malloc (5 *sizeof(Class));
    CS.ctr = 5;
    CS.max = 5;

    Initialize(&CS);

    //ClassListPtr IT;

    ClassList removedstudents = removeAll(&CS, 3, false);

    int x;
    for(x = 0; x < removedstudents.ctr; x++)
    {
        printf("%s", removedstudents.List[x].name.fname);
    } 

    printf("%d", removedstudents.ctr); 

    free(CS.List);
    free(removedstudents.List);

}

void Initialize(ClassList *L) 
{
    strcpy(L->List[0].id, "2013002061");
    strcpy(L->List[0].name.fname, "Patricia");
    strcpy(L->List[0].name.mname, "Elato");
    strcpy(L->List[0].name.lname, "Monserate");
    L->List[0].age = 17;
    L->List[0].DoB.month = 5;
    L->List[0].DoB.day = 12;
    L->List[0].DoB.year = 1999;
    L->List[0].gender = false; // Assuming false represents female

    strcpy(L->List[1].id, "2013002062");
    strcpy(L->List[1].name.fname, "chris");
    strcpy(L->List[1].name.mname, "Mas Gwaps");
    strcpy(L->List[1].name.lname, "sabandal");
    L->List[1].age = 18;
    L->List[1].DoB.month = 8;
    L->List[1].DoB.day = 9;
    L->List[1].DoB.year = 1999;
    L->List[1].gender = true;

    strcpy(L->List[2].id, "2013002063");
    strcpy(L->List[2].name.fname, "christie");
    strcpy(L->List[2].name.mname, "gwapa");
    strcpy(L->List[2].name.lname, "cobar");
    L->List[2].age = 22;
    L->List[2].DoB.month = 3;
    L->List[2].DoB.day = 10;
    L->List[2].DoB.year = 1999;
    L->List[2].gender = false;

    strcpy(L->List[3].id, "2013002064");
    strcpy(L->List[3].name.fname, "Godwin");
    strcpy(L->List[3].name.mname, "Granito");
    strcpy(L->List[3].name.lname, "Maderazo");
    L->List[3].age = 20;
    L->List[3].DoB.month = 3;
    L->List[3].DoB.day = 4;
    L->List[3].DoB.year = 1999;
    L->List[3].gender = true;

    strcpy(L->List[4].id, "2013002065");
    strcpy(L->List[4].name.fname, "chelsea");
    strcpy(L->List[4].name.mname, "rea");
    strcpy(L->List[4].name.lname, "pepito");
    L->List[4].age = 21;
    L->List[4].DoB.month = 3;
    L->List[4].DoB.day = 16;
    L->List[4].DoB.year = 1999;
    L->List[4].gender = false;

}

ClassList removeAll(ClassList *A, int month, bool genremv) 
{
    int x;
    int k;
    
    ClassList Removed;
    Removed.List = (Class*) malloc(A->ctr * sizeof(Class));
    Removed.max = 5;
    Removed.ctr = 0;
    for(x = 0; x < A->ctr; ++x)
    {
        if(A->List[x].DoB.month == month && A->List[x].gender == genremv){
            Removed.List[Removed.ctr++] = A->List[x];
        }
    } 

    for(x = 0, k = 0; x < A->ctr; ++x)
    {
        if(A->List[x].DoB.month != month && A->List[x].gender != genremv)
        {
            A->List[k++] = A->List[x];
        } 
    }

    A->ctr = k;

    return Removed;
}
