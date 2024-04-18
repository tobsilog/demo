#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "display.h"
#define MAX 20;
#define bracket1Rate 0.10;
#define bracket2Rate 0.15;
#define bracket3Rate 0.20;

employeeRecord populate(int);
employeeInfo newEmployee(int,int,int,name);
name addName(char [],char[],char);
void taxBracketSeparation(companyRecord *);


int main(){
    companyRecord companyLists;
    int i=0;
    int employeeInitialCount=0;


    printf("Input how many employees: ");
    scanf("%d",&employeeInitialCount);

    companyLists.employeeList=populate(employeeInitialCount);

    taxBracketSeparation(&companyLists);

	display(companyLists);


}


void taxBracketSeparation(companyRecord *companyList){
    /* This function will separate all employees from the employeeList and add them into their appropriate Tax Bracket based on their Gross Pay. After which calculate their Take Home pay based on their tax bracket rate. The function will take in a companyRecord pointer and will not return anything. */


    	//WRITE CODE TO SEPARATE EMPLOYEE LIST INTO PROPER TAX BRACKETS AND THEN
        //CALCULATE THEIR TAKE HOME PAY
}


employeeRecord populate(int count){

    /* This function will take in a count of how many employees to add, and return an employeeRecord */

    employeeRecord list;

	//Statement to allocate memory for an Array of Employees.
    list.employees=malloc(sizeof(employeeInfo)*count);
    int i=0;
    int idNum;
    int rate;
    int hrsWorked;
    char fName[20];
    char lName[20];
    char MI;

    for(i=0;i<count;i++){
    	printf("\n\n===EMPLOYEE %d===\n",i+1);

        //Write Code to Ask users for Input


    	list.employees[i]=newEmployee(/*Write code to complete function call */);
    	list.count++;

    	if(i==count-1){
    		printf("\n===============\n\n");
		}
	}

    return list;

}
employeeInfo newEmployee(int idNum,int rate,int hrsWorked,name employeeName){
    employeeInfo newEmp;

    newEmp.empName=employeeName;
    newEmp.idNum=idNum;
    newEmp.rate=rate;
    newEmp.hrsWorked=hrsWorked;

    //Write Code to Calculate grossSalary;




    return newEmp;

}
name addName(char fName[],char lName[],char MI){

    /* This function takes in 2 Strings and a Character, it will then populate a new name structure variable based on the parameters passed towards this function and aim to return it back to the calling function */

    name employeeName;

    strcpy(employeeName.fName,fName);
    strcpy(employeeName.lName,lName);
    employeeName.MI=MI;

    return employeeName;

}