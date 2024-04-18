#ifndef DISPLAY_H
#define DISPLAY_H
#define MAX 10

typedef struct{
    char fName[50];
    char lName[50];
    char MI;
}name;

typedef struct{
    name studentName;
    char studentAnswer[MAX];
    int studentScore;
}studentResults;

typedef struct{
    studentResults *record;
    int count;
}classRecord;

void display(classRecord);
studentResults addStudent(char[],char[],char,char[]);

#endif