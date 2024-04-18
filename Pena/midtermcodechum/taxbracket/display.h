#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

typedef struct{
    char fName[20];
    char lName[20];
    char MI;
}name;

typedef struct{
    name empName;
    int idNum;
    int grossSalary;
    int rate;
    int hrsWorked;
    float takeHomeSalary;
}employeeInfo;

typedef struct{
    employeeInfo *employees;
    //employeeInfo employees[MAX]; //Can use statically allocated array instead of above.
    // Do note only efficiently allocated arrays will be given full marks. e.g: An array that will contain 5 items, should only be allocated memory to accomodate those 5 items.
    int count;
}employeeRecord;

typedef struct{
    employeeRecord employeeList;
    employeeRecord bracket1; //Transfer all Employees who earn a grossSalary of 0-14,999, Tax rate = 10%, calculate takeHomeSalary here
    employeeRecord bracket2; //Transfer all Employees who earn a grossSalary of 15,000-25,999, Tax rate = 15%, calculate takeHomeSalary here
    employeeRecord bracket3; //Transfer all Employees who earn a grossSalary of 26,000 or higher, Tax rate = 20%, calculate takeHomeSalary here
}companyRecord;

void display(companyRecord);
employeeRecord populate(int);
employeeInfo newEmployee(int,int,int,name);
name addName(char [],char[],char);
void taxBracketSeparation(companyRecord *);

#endif