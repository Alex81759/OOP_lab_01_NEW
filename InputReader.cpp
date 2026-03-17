#include "InputReader.h"
#include <iostream>
#include <limits>
#include <stdexcept>

void clearInput() { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int InputReader::readMenuChoice(int minValue, int maxValue) const {
    int value = 0;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Choose menu item [" << minValue << ".." << maxValue << "]: ";
        std::cin >> value;
        isValid = std::cin.good() && value >= minValue && value <= maxValue;
        if (!isValid) {
            std::cout << "Invalid input. Try again.\n";
            clearInput();
        }
    }
    clearInput();
    return value;
}

int InputReader::readFigureTypeChoice() const {
    return readMenuChoice(1, 3);
}

std::size_t InputReader::readFigureIndex(std::size_t maxIndex) const {
    if (maxIndex == 0) {
        throw std::invalid_argument("No figures in collection.");
    }

    std::size_t index = 0;
    bool isValid = false;

    while (!isValid) {
        std::cout << "Enter figure number [1.." << maxIndex << "]: ";
        std::cin >> index;
        isValid = std::cin.good() && index >= 1 && index <= maxIndex;
        if (!isValid) {
            std::cout << "Invalid number. Try again.\n";
            clearInput();
        }
    }
    clearInput();
    return index - 1;
}

double InputReader::readDouble(const std::string& prompt) const {
    double value = 0.0;
    bool isValid = false;

    while (!isValid) {
        std::cout << prompt;
        std::cin >> value;
        isValid = std::cin.good();
        if (!isValid) {
            std::cout << "Invalid real number. Try again.\n";
            clearInput();
        }
    }
    clearInput();
    return value;
}

std::string InputReader::readNonEmptyString(const std::string& prompt) const {
    std::string text;
    bool isValid = false;

    while (!isValid) {
        std::cout << prompt;
        std::getline(std::cin, text);
        isValid = !text.empty();
        if (!isValid) {
            std::cout << "String must not be empty.\n";
        }
    }
    return text;
}

Point InputReader::readPoint(const std::string& prompt) const {
    std::cout << prompt << "\n";
    const double x = readDouble("  x: ");
    const double y = readDouble("  y: ");
    return Point(x, y);
}

std::unique_ptr<FigureParameters> InputReader::readFigureParameters(FigureType type) const {
    if (type == FigureType::Circle) {
        auto params = std::make_unique<CircleParameters>();
        params->name = readNonEmptyString("Enter circle name: ");
        params->center = readPoint("Enter circle center");
        params->radius = readDouble("Enter radius (>0): ");
        return params;
    }

    if (type == FigureType::Rectangle) {
        auto params = std::make_unique<RectangleParameters>();
        params->name = readNonEmptyString("Enter rectangle name: ");
        params->upperLeft = readPoint("Enter upper-left point");
        params->lowerRight = readPoint("Enter lower-right point");
        return params;
    }

    auto params = std::make_unique<TriangleParameters>();
    params->name = readNonEmptyString("Enter triangle name: ");
    params->a = readPoint("Enter point A");
    params->b = readPoint("Enter point B");
    params->c = readPoint("Enter point C");
    return params;
}
