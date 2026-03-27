#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"

class Triangle : public Figure {
    private:
        Point a;
        Point b;
        Point c;
    public:
        Triangle(const std::string& name, Point a, Point b, Point c);
        const std::type_info& getType() const override;
        double perimeter() const override;
        std::string parametersToString() const override;
    };


#endif // TRIANGLE_H
