//ValenTIME: We don't need a space
//challenge: create a function

#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    char *token = strtok(str, " ");
    printf("Modified string: ");
    
    printf("%s", token);
    while(token != NULL){
            token = strtok(NULL, " ");
            if (token != NULL) {
            printf("%s", token);
        }       
    }
    
}