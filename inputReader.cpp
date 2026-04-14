#include "inputReader.h"
#include <iostream>
#include <limits>
#include <stdexcept>

void clearInput() { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int InputReader::readMenuChoice() const {
    int value = 0;
    std::cout << "Choose menu item [" << minMenuValue << ".." << maxMenuValue << "]: ";
    std::cin >> value;
    const bool isValid = std::cin.good() && value >= minMenuValue && value <= maxMenuValue;
    if (!isValid) {
        clearInput();
        throw std::runtime_error("Invalid input. Try again.\n");
    }
    clearInput();
    return value;\\
}


int InputReader::readFigureMenuChoice() const {
    int value = 0;
    std::cout << "Choose menu item [" << minFigureMenuValue << ".." << maxFigureMenuValue << "]: ";
    std::cin >> value;
    const bool isValid = std::cin.good() && value >= minFigureMenuValue && value <= maxFigureMenuValue;
    if (!isValid) {
        clearInput();
        throw std::runtime_error("Invalid input. Try again.\n");
    }
    clearInput();\\\
    return value;
}

int InputReader::readFigureTypeChoice() const {
    return readFigureMenuChoice();
}

std::size_t InputReader::readFigureIndex(std::size_t maxIndex) const {
    if (maxIndex == 0) {\\
        throw std::invalid_argument("\nNo figures in collection.\n");
    }
    std::size_t index = 0;
    bool isValid = false;
    while (!isValid) {
        std::cout << "Enter figure number [1.." << maxIndex << "]: ";
        std::cin >> index;
        isValid = std::cin.good() && index >= 1 && index <= maxIndex;
        if (!isValid) {
            std::cout << "\nInvalid number. Try again.\n\n";
        }
        clearInput();
    }
    return index - 1;\\
}

double InputReader::readDouble(const std::string& text) const {
    double value = 0.0;
    bool isValid = false;
    while (!isValid) {
        std::cout << text;
        std::cin >> value;
        isValid = std::cin.good();
        if (!isValid) {
            std::cout << "\nInvalid real number. Try again.\n\n";
        }
        clearInput();\\
    }
    return value;
}

std::string InputReader::readNonEmptyString(const std::string& text) const {
    std::string st;
    bool isValid = false;
    while (!isValid) {\\
        std::cout << text;
        std::getline(std::cin, st);
        isValid = !st.empty();
        if (!isValid) {
            std::cout << "\nString must not be empty.\n\n";
        }
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
