#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"
#include "Point.h"
//сделать по аналогии с Circle.h
class Triangle : public Figure {
public:
    Triangle(const std::string& name, Point a, Point b, Point c);
    const std::string& getType() const override;
    double perimeter() const override;
    std::string parametersToString() const override;
private:
    Point a;
    Point b;
    Point c;
};


#endif // TRIANGLE_H
