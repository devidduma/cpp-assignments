#include <iostream>
using namespace std;

struct line2
{
    float a, b, c;
};

struct Point
{
    float x, y;
};

float slope(line2 line)
{
    return (-line.a / line.b); /* ax+by+c=0,=>y=-(b/a)x+c slope is the coefficient before x:-b/a*/
}

bool isInLine(line2 line, Point p1)
{
    return line.a * p1.x + line.b * p1.y + line.c == 0; /* we check if a given point is in line by substituting*/
}

bool isParalel(line2 line, line2 line1)
{
    return slope(line) == slope(line1); /* 2 lines are parallel if they have the same slope*/
}

float x_intersect(line2 line)
{
    return -line.c / line.a; /* ax+by+c=0,y=0 so ax+c=0 and x=-c/a ? */
}

float y_intersect(line2 line)
{
    return -line.b / line.a; /* ax+by+c=0,x=0 so by+c=0 and y=-b/a ? */
}

int main() {
}
