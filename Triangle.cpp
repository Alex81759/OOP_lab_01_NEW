#include "Triangle.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

#define EPS 1e-9

double distance(const Point& p1, const Point& p2) {
    const double dx = p1.getX() - p2.getX();
    const double dy = p1.getY() - p2.getY();
    return std::sqrt(dx * dx + dy * dy);
}

Triangle::Triangle(const std::string& name, Point a, Point b, Point c) : Figure(name), a(a), b(b), c(c) {
    const double ab = distance(a, b);
    const double bc = distance(b, c);
    const double ca = distance(c, a);
    if (ab <= EPS || bc <= EPS || ca <= EPS) {
        throw std::invalid_argument("Triangle error: identical vertices.");
    }
    const double area2 = std::fabs(
        (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX())
    );
    if (area2 <= EPS) {
        throw std::invalid_argument("Triangle error: degenerate triangle.");
    }
}

const std::string& Triangle::getType() const {
    return typeid(Triangle).name();
}

double Triangle::perimeter() const {
    return distance(a, b) + distance(b, c) + distance(c, a);
}

std::string Triangle::parametersToString() const {
    return "name = " + name + ", A = (" + std::to_string(a.getX()) + ", " + std::to_string(a.getY()) + ")" + ", B = (" + std::to_string(b.getX()) + ", " + std::to_string(b.getY()) + ")" + ", C = (" + std::to_string(c.getX()) + ", " + std::to_string(c.getY()) + ")";
}
