#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "display.h"
#define MAX 10


void populate(classRecord *,int);
void checkExams(char[],classRecord*);


int main(){
    char answerKey[]="TTTFFTTFTF";
    classRecord examRecords;
    int classCount;
    examRecords.count=0;

    printf("How many students in the class? ");
    //Input for class count


    //Write code to only allow a class of more than 0


    //Write code to initialize array of students.

    populate(/*Complete function call*/);
    checkExams(/*Complete function call*/);

    display(/*Complete function call*/);



}

void checkExams(char answerKey[],classRecord *examRecord){

    //Write Code to check exams here and record the students score
}

void populate(classRecord *examRecord,int classCount){
   int i=0;
	int x=0;
	char fName[50];
	char lName[50];
	char MI;
	char studentAnswer[MAX];

	for(i=0;i<classCount;i++){
	printf("===STUDENT %d===\n\n",i+1);

   //Write code for student inputs.


    //Write code to properly store the inputted values.
	}



}