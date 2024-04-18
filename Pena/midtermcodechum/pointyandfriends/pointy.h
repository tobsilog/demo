#ifndef POINTY_H
#define POINTY_H

typedef char String[20];

typedef struct {
    int x, y;
} MyPoint;

typedef struct {
    MyPoint *points;
    int count;
    int max;
} Points;

/**
    The function displayPoint() will accept MyPoint and display the x and y coordinates.
*/
void displayPoint(MyPoint p);

/**
    The function displayPointMsg() will accept a MyPoint and will display the x and y coordinates with the location and position.
*/
void displayPointMsg(MyPoint p);

/**
    The function identifyPoint() will determine the location of the given point base in the cartesian plane.
*/
int identifyPoint(MyPoint p);

/**
    The function createPoint() will make a MyPoint based from the x and y coordinate.
*/
MyPoint createPoint(int x, int y);

/**
    Initialize a structure of a collection of points (dynamically allocated) based on the max value.
*/
void initPoints(Points *p, int max);

/**
    Initialize a structure of a collection of points (statically allocated) based on the max value of 30.
*/
Points createPoints();

/**
    The function displayAllPointsWithStartIndex() will display the points in the collection from the "start" value until to the end.
*/
void displayAllPointsWithStartIndex(Points p, int start);

//Points getMrPointyAndFriends(Points points);

/**
    Populates with initial point values values in "p".
*/
void populatePoints(Points *p);

#endif