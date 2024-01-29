#include <stdio.h>

int main(){
int current;

   printf("Enter a number: ");
   scanf("%d", &current);

   while(current!=1){
       if(current % 2 == 0){
           current/=2;
           printf("%d ", current);
       } else {
           current = current * 3 + 1;
           printf("%d ", current);
       }

   }
   return 0;

}