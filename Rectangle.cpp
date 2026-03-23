#include "Rectangle.h"
#include <sstream>
#include <stdexcept>
//сделать по аналогии с Circle.cpp
namespace {
constexpr double EPS = 1e-9;
}

Rectangle::Rectangle(const std::string& name, Point upperLeft, Point lowerRight) : Figure(name), upperLeft_(upperLeft), lowerRight_(lowerRight) {
    const bool validX = upperLeft_.getX() + EPS < lowerRight_.getX();
    const bool validY = upperLeft_.getY() > lowerRight_.getY() + EPS;

    if (!validX || !validY) {
        throw std::invalid_argument("Rectangle error: invalid corners (upper-left / lower-right).");
    }
}

std::string Rectangle::getType() const {
    return "Rectangle";
}

double Rectangle::perimeter() const {
    const double width = lowerRight_.getX() - upperLeft_.getX();
    const double height = upperLeft_.getY() - lowerRight_.getY();
    return 2.0 * (width + height);
}

std::string Rectangle::parametersToString() const {
    std::ostringstream out;
    out << "name = " << name
        << ", upperLeft = (" << upperLeft_.getX() << ", " << upperLeft_.getY() << ")"
        << ", lowerRight = (" << lowerRight_.getX() << ", " << lowerRight_.getY() << ")";
    return out.str();
}
