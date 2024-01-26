#include <stdio.h>
#include <string.h>

int main (){
    int age, year;
    char name[50];
    

    printf("Enter name: ");
    scanf(" %[^\n]", &name);
    
    int size = strlen(name);

    //printf("%s", name);
    
    if(name[size - 1] == 'a' || name[size - 1] == 'e' || name[size - 1] == 'i' || name[size - 1] == 'o' || name[size - 1] == 'u'){
        printf("Enter age: ");
        scanf("%d", &age);
        if(age % 2 == 0){
            printf("Wow, you're special!");
        } else {
            printf("Enter birth year: ");
            scanf("%d", &year);
            if(year % 2 == 0){
                printf("Oh, you're still special!");
            } else{
                printf("You will be special next year.");
            }
        }
    } else {
        printf("You're awesome!");
    }

    
}

// #include <stdio.h>
// #include <string.h>

// int main (){
//     int age, year;
//     char name[50];

//     printf("Enter name: ");
//     scanf("%49s", name); // Limit input to prevent buffer overflow, leaving space for null terminator

//     int size = strlen(name); // Use strlen to get the length of the string

//     if(name[size - 1] == 'a' || name[size - 1] == 'e' || name[size - 1] == 'i' || name[size - 1] == 'o' || name[size - 1] == 'u'){
//         printf("Enter age: ");
//         scanf("%d", &age);
//         if(age % 2 == 0){
//             printf("Wow, you're special!");
//         } else {
//             printf("Enter birth year: ");
//             scanf("%d", &year);
//             if(year % 2 == 0){
//                 printf("Oh, you're still special!");
//             } else{
//                 printf("You will still be special next year.");
//             }
//         }
//     } else {
//         printf("You're awesome!");
//     }

//     return 0; // Added return statement to comply with function signature
// }