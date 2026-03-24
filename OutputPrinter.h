#ifndef OUTPUTPRINTER_H
#define OUTPUTPRINTER_H

#include <string>
#include "FigureCollection.h"

class OutputPrinter {
    public:
        void printMainMenu() const;
        void printFigureTypeMenu() const;
        void printFiguresWithParameters(const FigureCollection& collection) const;
        void printFiguresWithPerimeter(const FigureCollection& collection) const;
        void printTotalPerimeter(double value) const;
        void printMessage(const std::string& message) const;
        void printError(const std::string& error) const;
};

#endif // OUTPUTPRINTER_H
