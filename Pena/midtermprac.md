[]StudList populateList()


[]displayList(StudList class) function will display the information of all the elements in the list. Each lists elements information will be displayed in a horizontal line


[]insertAtPos(StudList *class, int index, Studtype student) function will insert a given element at a given position in the given list if the list is not full. position starts at 0. shift elements to make room for the new element


[]deleteElem() given the list and the id number the function will delete the student record from the list by shifting the succeeding elements. in addition return the deleted record to the calling functio if the given id does not exist reurn a dummy record with "XXX" for string fields and 0 integral fields


[]deleteAllCourse() given a list and a course the function will delete all the student records bearing the given course and return to the calling function the number of deleted records.


[]sortList() given the list the function will sort the list in ascending order according to lastname using selection sort technique


//sortbyyear()