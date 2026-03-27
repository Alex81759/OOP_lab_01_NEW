#include "rectangle.h"
#include <stdexcept>

#define EPS 1e-9

Rectangle::Rectangle(const std::string& name, Point upperLeft, Point lowerRight) : Figure(name), upperLeft(upperLeft), lowerRight(lowerRight) {
    const bool validX = upperLeft.getX() + EPS < lowerRight.getX();
    const bool validY = upperLeft.getY() > lowerRight.getY() + EPS;
    if (!validX || !validY) {
        throw std::invalid_argument("Rectangle error: invalid corners (upper-left / lower-right).");
    }
}

const std::type_info& Rectangle::getType() const {
    return typeid(Rectangle);
}

double Rectangle::perimeter() const {
    const double width = lowerRight.getX() - upperLeft.getX();
    const double height = upperLeft.getY() - lowerRight.getY();
    return 2.0 * (width + height);
}

std::string Rectangle::parametersToString() const {
    return "name = " + name + ", upperLeft = (" + std::to_string(upperLeft.getX()) + ", " + std::to_string(upperLeft.getY()) + "), lowerRight = (" + std::to_string(lowerRight.getX()) + ", " + std::to_string(lowerRight.getY()) + ")";

}
