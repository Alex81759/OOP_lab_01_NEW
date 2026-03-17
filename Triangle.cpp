#include "Triangle.h"
#include <cmath>
#include <sstream>
#include <stdexcept>

namespace {
constexpr double EPS = 1e-9;

double distance(const Point& p1, const Point& p2) {
    const double dx = p1.getX() - p2.getX();
    const double dy = p1.getY() - p2.getY();
    return std::sqrt(dx * dx + dy * dy);
}
}

Triangle::Triangle(const std::string& name, Point a, Point b, Point c) : Figure(name), a_(a), b_(b), c_(c) {
    const double ab = distance(a_, b_);
    const double bc = distance(b_, c_);
    const double ca = distance(c_, a_);

    if (ab <= EPS || bc <= EPS || ca <= EPS) {
        throw std::invalid_argument("Triangle error: identical vertices.");
    }

    const double area2 = std::fabs(
        (b_.getX() - a_.getX()) * (c_.getY() - a_.getY()) -
        (b_.getY() - a_.getY()) * (c_.getX() - a_.getX())
    );

    if (area2 <= EPS) {
        throw std::invalid_argument("Triangle error: degenerate triangle.");
    }
}

std::string Triangle::getType() const {
    return "Triangle";
}

double Triangle::perimeter() const {
    return distance(a_, b_) + distance(b_, c_) + distance(c_, a_);
}

std::string Triangle::parametersToString() const {
    std::ostringstream out;
    out << "name = " << name_
        << ", A = (" << a_.getX() << ", " << a_.getY() << ")"
        << ", B = (" << b_.getX() << ", " << b_.getY() << ")"
        << ", C = (" << c_.getX() << ", " << c_.getY() << ")";
    return out.str();
}
