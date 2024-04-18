#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 50

typedef char String[50];

typedef struct {
    String LName;
    String FName;
    char MI;
} nametype;

typedef struct  {
    nametype name;
    int ID;
    String course;
    int year;
} Studtype;

typedef struct {
    Studtype *Stud;
    int ctr;
} StudList;

Studtype * populateListret()
{
    //Studtype studA[] = {{{"AAA", "AAA", 'A'}, 111111111, "BSCS", 1}, {{"BBB", "BBB", 'B'}, 22222222, "BSCS", 1}, {{"CCC", "CCC", 'C'}, 33333333, "BSCS", 1}};

    Studtype *studA = malloc(SIZE * sizeof(Studtype));

    // studA[0] = {{"AAA", "AAA", 'A'}, 111111111, "BSCS", 1};
    // studA[1] = {{"BBB", "BBB", 'B'}, 22222222, "BSCS", 1};
    // studA[2] = {{"CCC", "CCC", 'C'}, 33333333, "BSCS", 1};

    strcpy(studA[0].name.LName, "AAA");
    strcpy(studA[0].name.FName, "AAA");
    studA[0].name.MI = 'A';
    studA[0].ID = 111111111;
    strcpy(studA[0].course, "BSCS");
    studA[0].year = 1;

    strcpy(studA[1].name.LName, "BBB");
    strcpy(studA[2].name.FName, "BBB");
    studA[1].name.MI = 'B';
    studA[1].ID = 22222222;
    strcpy(studA[0].course, "BSIT");
    studA[1].year = 1;

    strcpy(studA[2].name.LName, "CCC");
    strcpy(studA[2].name.FName, "CCC");
    studA[2].name.MI = 'C';
    studA[2].ID = 33333333;
    strcpy(studA[2].course, "BSCS");
    studA[2].year = 1;

    //int numElem = sizeof(studA)/ sizeof(Studtype);

    return studA;
}

void displayList(StudList class) {
    int x;
    for(x = 0; x < class.ctr;x++){
        printf("Name: %s, %s %c\n", class.Stud[x].name.LName, class.Stud[x].name.FName, class.Stud[x].name.MI);
        printf("ID:%d\n", class.Stud[x].ID);
        //etc...
    }
}

void insertAtPos(StudList *class, int index)
{
    if((class->ctr + 1) < SIZE)
    {
        int y;
        for(y = class->ctr; y > index; y--){
            class->Stud[y] = class->Stud[y - 1];
        }
        class->ctr++;
    }
    
    //class->Stud[index] = addStudent();
}

Studtype deleteElem(StudList *class, int IDremv)
{
    int x, y;
    for(x = 0; x < class->ctr && class->Stud[x].ID != IDremv; x++)
    {
    }

    if(x == class->ctr){
        Studtype notfound = {{"XXX", "XXX", 'X'}, 00000000, "XXXX", 0};
        return notfound;
    } else 
    {
        return class->Stud[x];
    }

    for(; x < class->ctr; x++)
    {
        class->Stud[x] = class->Stud[x + 1];
    }
    class->ctr--;
}

int deleteOccurences(StudList *class, int IDremv)
{
    //deleteAllCourse 
    int x, k, count;
    for(x = 0, k = 0; x < class->ctr; x++)
    {
        if(class->Stud[x].ID != IDremv)
        {
            class->Stud[k++] = class->Stud[x];
        } else {
            count++;
        }
    }
    return count;
}

void sort(StudList *class)
{ 
    int x, y, index;
    // for(x = 0; x < class->ctr - 1; x++)
    // {
    //     index = x;
    //     for(y = x + 1; y < class->ctr - 1; y++){
    //         if(class->Stud[index].ID > class->Stud[y].ID){
    //             index = y;
    //         }
    //     }
    //     //swap
    //     Studtype temp = class->Stud[index];
    //     class->Stud[index] = class->Stud[x];
    //     class->Stud[x] = temp;

    // }

    //last name version
    for(x = 0; x < class->ctr - 1; x++)
    {
        index = x;
        for(y = x + 1; y < class->ctr; y++)
        {
            if(strcmp(class->Stud[index].name.LName, class->Stud[y].name.LName) > 0)
            {
                index = y;
            }
        }
        Studtype temp = class->Stud[index];
        class->Stud[index] = class->Stud[x];
        class->Stud[x] = temp;
    }
}

void insertSorted(StudList *class, Studtype student)
{
    int x;
    for(x = 0; x < class->ctr && class->Stud[x].ID < student.ID; x++)
    {}

    int y;
    for(y = class->ctr; y > x; y--)
    {
        class->Stud[y] = class->Stud[y - 1];
    }

    class->Stud[x] = student;

    class->ctr++;

}

void main() {
    
    StudList Class = {populateListret(), 3};

    displayList(Class);

    Studtype find = deleteElem(&Class, 22222222);

    printf("%s", find.name.LName);

}