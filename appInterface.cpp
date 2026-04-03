#include "appInterface.h"

MainMenuInterface::MainMenuInterface(const InputReader& in, const OutputPrinter& out) : input(in), output(out) {}

int MainMenuInterface::readAndChoice() const {
    while (true) {
        try {
            output.printMainMenu();
            return input.readMenuChoice();
        } catch (const std::exception&) {
            output.printError("Invalid input. Try again.\n");
        }
    }
}

FigureTypeMenuInterface::FigureTypeMenuInterface(const InputReader& in, const OutputPrinter& out) : input(in), output(out) {}

int FigureTypeMenuInterface::readAndChoice() const {
    while (true) {
        try {
            output.printFigureTypeMenu();
            return input.readFigureMenuChoice();
        } catch (const std::exception&) {
            output.printError("Invalid input. Try again.\n");
        }
    }
}
