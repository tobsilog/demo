#include <stdio.h>
#include <stdlib.h>
#include "pointy.h"

/**
    Function: getMrPointyAndFriends()
    Description: The function will get all points with the same cluster (location) in the cartesian plane. Mr Pointy is the first index in the collection followed by the others.
    Param: points - a collection of points starting with Mr. Pointy followed by the others.
    Return: a collection of Mr Pointy and with his friends. Still Mr Pointy will still be in the first index follwed by his friends.
*/
Points getMrPointyAndFriends(Points points) {
    // [2] to do code login here

}

void main() {
    Points points = createPoints(30);
    Points friends;
    int x, y;

    populatePoints(&points);

    printf("Enter x - coordinate: ");
    scanf("%d", &x);
    printf("Enter y - coordinate: ");
    scanf("%d", &y);

    // [1] insert code after this comment to override the first value in the populated points by the new value x and y known as Mr. Pointy


    displayPointMsg(points.points[0]);
    // [3] insert you function call of getMrPointyAndFriends() after this line

    printf("Friends: ");
    // [4] use the function displayAllPointsWithStartIndex()
}