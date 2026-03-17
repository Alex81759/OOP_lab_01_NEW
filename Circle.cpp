#include "Circle.h"
#include <sstream>
#include <stdexcept>

namespace {
constexpr double EPS = 1e-9;
constexpr double PI = 3.14159265358979323846;
}

Circle::Circle(const std::string& name, Point center, double radius) : Figure(name), center_(center), radius_(radius) {
    if (radius <= EPS) {
        throw std::invalid_argument("Circle error: radius must be > 0.");
    }
}

std::string Circle::getType() const {
    return "Circle";
}

double Circle::perimeter() const {
    return 2.0 * PI * radius_;
}

std::string Circle::parametersToString() const {
    std::ostringstream out;
    out << "name = " << name_
        << ", center = (" << center_.getX() << ", " << center_.getY() << ")"
        << ", radius = " << radius_;
    return out.str();
}
//"sdfsdf" + " sdfsdfsdf" strcatcat перегрузка оператора
//позволяет определить для объектов классов втроенные операторы, такие как +, -, * и т.д.
//Для определения оператора для объектов своего класса, необходимо определить функцию,
//название которой содержит слово operator
