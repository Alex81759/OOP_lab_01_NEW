#include "inputReader.h"
#include <iostream>
#include <limits>
#include <stdexcept>

void InputReader::clearInput() const {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::size_t InputReader::readFigureIndex(std::size_t maxIndex) const {
    std::size_t index = 0;
    std::cout << "Enter figure number [1.." << maxIndex << "]: ";
    std::cin >> index;
    if (!std::cin.good() || index < 1 || index > maxIndex) {
        clearInput();
        throw std::runtime_error("Invalid number. Try again.\n");
    }
    clearInput();
    return index - 1;
}

double InputReader::readDouble(const std::string& text) const {
    double value = 0.0;
    std::cout << text;
    std::cin >> value;
    if (!std::cin.good()) {
        clearInput();
        throw std::runtime_error("Invalid real number. Try again.\n");
    }
    clearInput();
    return value;
}

std::string InputReader::readNonEmptyString(const std::string& text) const {
    std::string st;
    std::cout << text;
    std::getline(std::cin >> std::ws, st);
    if (st.empty()) {
        throw std::runtime_error("String must not be empty.\n");
    }
    return st;
}


Point InputReader::readPoint(const std::string& text) const {
    std::cout << text << "\n";
    const double x = readDouble("x: ");
    const double y = readDouble("y: ");
    return Point(x, y);
}

std::unique_ptr<FigureParameters> InputReader::readFigureParameters(const std::type_info&  type) const {
    std::unique_ptr<FigureParameters> result;
    if (type == typeid(Circle)) {
        const std::string name = readNonEmptyString("Enter circle name: ");
        const Point center = readPoint("Enter circle center");
        const double radius = readDouble("Enter radius (>0): ");
        result = std::make_unique<CircleParameters>(name, center, radius);
    }
    else if (type == typeid(Rectangle)) {
        const std::string name = readNonEmptyString("Enter rectangle name: ");
        const Point upperLeft = readPoint("Enter upper-left point");
        const Point lowerRight = readPoint("Enter lower-right point");
        result = std::make_unique<RectangleParameters>(name, upperLeft, lowerRight);
    }
    else if (type == typeid(Triangle)){
        const std::string name = readNonEmptyString("Enter triangle name: ");
        const Point a = readPoint("Enter point A");
        const Point b = readPoint("Enter point B");
        const Point c = readPoint("Enter point C");
        result = std::make_unique<TriangleParameters>(name, a, b, c);
    }
    return result;
}
