// rugfit2.cpp - calculates fit of rug to a floor
// Shuo Wang (Kevin) Apr 2
// Perm number: 9438425

#include <iostream>
using namespace std;

// definition of class Rectangle
// (usually would be in a separate file named rectangle.h)
class Rectangle
{

public:
    // DECLARE a parameterized constructor to set the width and length
    Rectangle(double w, double l);
    // DECLARE accessors to get the width and length
    double getWidth() const;
    double getLength() const;
    // DECLARE mutators to set the width and lengtg
    void setWidth(double w);
    void setLength(double l);
    // DECLARE (const) METHOD TO RETURN AREA OF RECTANGLE
    double area() const;

    double getX() const;
    double getY() const;

    void setX(double x1);
    void setY(double y1);

    bool intersects(Rectangle const &other) const;
    Rectangle intersection(Rectangle const &other) const;

private:
    double width, length, x, y;

}; // end of class definition

// implementation of class Rectangle here to main function
// (usually would be in a separate file named rectangle.cpp,
// and this separate file would #include "rectangle.h")

// IMPLEMENT CONSTRUCTOR USING INITIALIZATION LIST
Rectangle::Rectangle(double w, double l) : width(w), length(l) {}

// IMPLEMENT ACCESSORS and MUTATORS
double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getLength() const {
    return length;
}

void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setLength(double l) {
    length = l;
}

// IMPLEMENT THE AREA METHOD HERE
double Rectangle::area() const {
    return width * length;
}

double Rectangle::getX() const {
    return x;
}

double Rectangle::getY() const {
    return y;
}

void Rectangle::setX(double x1) {
    x = x1;
}

void Rectangle::setY(double y1) {
    y = y1;
}

bool Rectangle::intersects(Rectangle const &other) const {
    if (x + width > other.x && other.x + other.width > x && y + length > other.y && other.y + other.length > y){
        return true;
    }
    return false;
    
}

Rectangle Rectangle::intersection(Rectangle const &other) const {
    Rectangle result(0, 0);

    if (intersects(other)) {
        result.setX(max(x, other.x));
        result.setY(min(y, other.y));
        result.setLength(min(x + length, other.x + other.length) - max(x, other.x));
        result.setWidth(min(y, other.y) - max(y - width, other.y - other.width));
    }

    return result;
}

// change main where instructed in UPPER CASE below
// (usually would #include "rectangle.h" before main)
int main() {
    // test for intersect

    Rectangle a1(10.3, 20.1);
    a1.setX(0);
    a1.setY(20);

    Rectangle a2(3.2, 10.7);
    a2.setX(0);
    a2.setY(90);

    Rectangle a3(7.83, 2.01);
    a3.setX(9.8);
    a3.setY(20);

    Rectangle a4(0.9, 0.7);
    a4.setX(10.5);
    a4.setY(20.1);

    cout << a1.intersects(a2)
        << " " << a2.intersects(a1)
        << " " << a3.intersects(a4)
        << " " << a1.intersects(a3) << endl;

    Rectangle a5 = a4.intersection(a3);
    cout << a5.getLength() << " " << a5.getWidth() << " " << a5.getX() << " " << a5.getY() << endl;

    Rectangle a6 = a1.intersection(a2);
    cout << a6.getLength() << endl;


    double width, length;
    Rectangle wall(0, 0);
    Rectangle paper(0, 0);
    cout << "Enter width and length of wall: " << endl;
    cin >> width >> length;
    wall.setWidth(width);
    wall.setLength(length);
    double wallArea = wall.area();

    cout << "Enter width and length of a single strip of wallpaper: " << endl;
    cin >> width >> length;
    paper.setWidth(width);
    paper.setLength(length);
    double wallpaperArea = paper.area();

    Rectangle door(0, 0);
    Rectangle window(0, 0);
    int doorNum, windowNum;
    cout << "Enter total number of door(s) and window(s): " << endl;
    cin >> doorNum >> windowNum;
    cout << "Enter width and length of a door: " << endl;
    cin >> width >> length;
    door.setWidth(width);
    door.setLength(length);
    double doorArea = door.area() * doorNum;
    
    cout << "Enter width and length of a window: " << endl;
    cin >> width >> length;
    window.setWidth(width);
    window.setLength(length);
    double windowArea = window.area() * windowNum;

    int pieces = (wallArea - doorArea - windowArea) / wallpaperArea + 1;
    cout << "You will need " << pieces << " strips of wallpaper!" << endl;



    // original lab01 code
    Rectangle rug(0,0); // will be updated below

    // create Rectangle named "floor" for sizes input by user
    cout << "enter width and length of floor: ";
    cin >> width >> length;
    const Rectangle floor(width, length); // note: const object

    // RESET Rectangle NAMED "rug" FOR SIZES INPUT BY USER
    cout << "enter width and length of rug: ";
    cin >> width >> length;
    rug.setWidth(width);
    rug.setLength(length);
    
    // DO NOT CHANGE ANYTHING BELOW (if you do, you will earn 0 points,
    // no matter what submit.cs says is your "tentative" score)

    // print results
    cout << "floor area: " << floor.area() << endl;
    cout << "rug area: " << rug.area() << endl;
    double leftover = rug.area() - floor.area();
    cout << "leftover rug area: " <<
        (leftover > 0 ? leftover : 0) << endl;
    cout << "empty floor area: " <<
        (leftover < 0 ? -leftover : 0) << endl;

    return 0;
}
