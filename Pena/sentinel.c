#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
    char input[MAX_STR_LEN];
    char sentinel[] = ".";
    
    printf("Enter a sequence of strings separated by spaces (type ' .' to end):\n");

    // Read strings until the sentinel is encountered
    while (1) {
        // Read a string
        scanf("%s", input);

        // Check if the input is equal to the sentinel
        if (strcmp(input, sentinel) == 0) {
            printf("Input ended.\n");
            break; // Exit the loop if sentinel is encountered
        }

        // Process the input string
        printf("You entered: %s\n", input);
    }

    return 0;
}