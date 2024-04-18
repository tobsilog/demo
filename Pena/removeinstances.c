#include <stdio.h>

void deleteAll(int list[], int num, int *count){
    int k = 0;
    int og_count = *count;
    for (int i = 0; i < og_count; ++i){
        if (list[i]!=num){
            list[k++] = list[i];
        } else{
            (*count)--;
        }
    }
}
void display(int list[], int count){
    for (int i = 0; i < count; ++i){
        if (i != count-1){
            printf("%d, ",list[i]);
        } else{
            printf("%d",list[i]);
        }
    }
}
void main(){
    int count = 8;
    int list[8] = {1,2,2,2,3,4,5,2};
    display(list, count);
    deleteAll(list,2,&count);
    printf("\n");
    display(list,count);
        
}