#include "outputPrinter.h"
#include <iostream>
#include <iomanip>

void OutputPrinter::printMainMenu() const {
    std::cout << "=== MENU ===\n";
    std::cout << "1. Add figure\n";
    std::cout << "2. Show list (type + parameters)\n";
    std::cout << "3. Show list (type + perimeter)\n";
    std::cout << "4. Show total perimeter\n";
    std::cout << "5. Sort by perimeter (ascending)\n";
    std::cout << "6. Remove figure by number\n";
    std::cout << "7. Remove figures with perimeter greater than value\n";
    std::cout << "0. Exit\n";
}

void OutputPrinter::printFigureTypeMenu() const {
    std::cout << "Choose figure type:\n";
    std::cout << "1. Circle\n";
    std::cout << "2. Rectangle\n";
    std::cout << "3. Triangle\n";
}

void OutputPrinter::printFiguresWithParameters(const FigureCollection& collection) const {
    const auto& figures = collection.getAll();
    if (figures.empty()) {
        std::cout << "\nCollection is empty.\n";
        return;
    }
    for (std::size_t i = 0; i < figures.size(); ++i) {
        std::cout << i + 1 << ") " << std::string(figures[i]->getType().name()).substr(1) << " | " << figures[i]->parametersToString() << "\n";
    }
}

void OutputPrinter::printFiguresWithPerimeter(const FigureCollection& collection) const {
    const auto& figures = collection.getAll();
    if (figures.empty()) {
        std::cout << "\nCollection is empty.\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(6);
    for (std::size_t i = 0; i < figures.size(); ++i) {
        std::cout << i + 1 << ") " << std::string(figures[i]->getType().name()).substr(1) << " | perimeter=" << figures[i]->perimeter() << "\n";
    }
}

void OutputPrinter::printTotalPerimeter(double value) const {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total perimeter: " << value << "\n";
}

void OutputPrinter::printMessage(const std::string& message) const {
    std::cout << message << "\n";
}

void OutputPrinter::printError(const std::string& error) const {
    std::cout << "\nError: " << error << "\n";
}
