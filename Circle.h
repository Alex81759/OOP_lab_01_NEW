#ifndef CIRCLE_H
#define CIRCLE_H

#include "Figure.h"
#include "Point.h"

class Circle : public Figure {
    private:
        Point center;
        double radius;
    public:
        Circle(const std::string& name, Point center, double radius);
        const std::string& getType() const;
        double perimeter() const override;
        std::string parametersToString() const override;
};

#endif // CIRCLE_H
