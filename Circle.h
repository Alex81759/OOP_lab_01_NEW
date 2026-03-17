#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
public:
    Circle(const std::string& name, Point center, double radius);
    std::string getType() const override;
    double perimeter() const override;
    std::string parametersToString() const override;
private:
    Point center_;
    double radius_;
};

#endif // CIRCLE_H
