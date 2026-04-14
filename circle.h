#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"
#include "point.h"

class Circle : public Figure {
    private:
        Point center;
        double radius;
    public:
        Circle(const std::string& name, const Point& center, double radius);
        const std::type_info& getType() const override;
        double perimeter() const override;
        std::string parametersToString() const override;
};

#endif // CIRCLE_H
