#include <stdio.h>

#include <math.h>

int main(){

int a, b, c;

double root1, root2;

printf("Enter the coefficients a, b, c: ");

scanf(" %d, %d, %d", &a, &b, &c);

if(a == 0){

return 0;

}

double discriminant = b * b - 4 * a * c;

//printf("%lf", discriminant);

if(discriminant > 0){

//get roots using sqrt but first code pani

root1 = (- b + sqrt(discriminant)) / ( 2.0 * a);

root2 = (- b - sqrt(discriminant)) / ( 2.0 * a);

}

else if(discriminant == 0){

root1 = root2 = (- b) / 2.0 * a;

}

else if(discriminant < 0){

printf("Not real. \n");

root1 = root2 = 0;

}

printf("Root 1 : %.2lf & Root 2 : %.2lf", root1, root2);

}