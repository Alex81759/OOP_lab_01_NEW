#include "Circle.h"
#include <stdexcept>
#include <cmath>

#define _USE_MATH_DEFINES
#define EPS 1e-9

const std::string CIRCLE_TYPE = "Circle";

Circle::Circle(const std::string& name, Point center, double radius) : Figure(name), center(center), radius(radius) {
    if (radius <= EPS) {
        throw std::invalid_argument("Circle error: radius must be > 0.");
    }
}

const std::string& Circle::getType() const {
    return CIRCLE_TYPE;
}

double Circle::perimeter() const {
    return 2.0 * M_PI * radius;
}

std::string Circle::parametersToString() const {
    return "name = " + name + ", center = (" + std::to_string(center.getX()) + ", " + std::to_string(center.getY()) + "), radius = " + std::to_string(radius);
}

