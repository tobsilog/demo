#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef char String[20];

typedef struct{
    float price;
    int quantity;
    String name;
} dish;

typedef struct{
    dish entree[3];
    dish sides[3];
    dish desserts[3];
} menu;

dish createDish(float price, String name, int quantity);
menu loadMenu();
void displayEntree(menu main_menu, int size);
void displaySides(menu main_menu, int size);
void displayDesserts(menu main_menu, int size);
void addOrder(dish *order_dish, int *total, dish all_orders[]);
void displayOrder(dish all_orders[], int total);
float sumAll(dish all_orders[], int total);
void removeDish(dish all_orders[], int *total, int index, int input, menu *main_menu);

void main(){
    
    menu mainmenu = loadMenu();
}

menu loadMenu(){
    menu newmenu;

    newmenu.desserts[0] = createDish(50.2, "Mango Sago", 2);
    newmenu.desserts[1] = createDish(20.4, "Ice Cream", 2);
    newmenu.desserts[2] = createDish(35.6, "Binignit", 2);

    newmenu.entree[0] = createDish(120.1, "Carbonara", 2);
    newmenu.entree[1] = createDish(80.7, "Cordon Blu", 2);
    newmenu.entree[2] = createDish(110.3, "Fried Chicken", 2);

    newmenu.sides[0] = createDish(60.2, "Fries", 2);
    newmenu.sides[1] = createDish(75.4, "Potato Slice", 2);
    newmenu.sides[2] = createDish(40.6, "Corn", 2);

    return newmenu;
}

dish createDish(float price, String name, int quantity)
{
    dish temp;

    temp.price = price;
    strcpy(temp.name, name);
    temp.quantity = quantity;

    return temp;
}

void displayEntree(menu main_menu, int size)
{
    
}