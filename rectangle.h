#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include "point.h"

class Rectangle : public Figure {
    private:
        Point upperLeft;
        Point lowerRight;
    public:
        Rectangle(const std::string& name, Point upperLeft, Point lowerRight);
        const std::type_info& getType() const override;
        double perimeter() const override;
        std::string parametersToString() const override;
};

#endif // RECTANGLE_H
