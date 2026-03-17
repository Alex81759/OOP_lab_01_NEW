#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"
#include "Point.h"

class Rectangle : public Figure {
public:
    Rectangle(const std::string& name, Point upperLeft, Point lowerRight);
    std::string getType() const override;
    double perimeter() const override;
    std::string parametersToString() const override;
private:
    Point upperLeft_;
    Point lowerRight_;
};


#endif // RECTANGLE_H
