#include "appInterface.h"

MainMenu::MainMenu(const InputReader& in, const OutputPrinter& out) : input(in), output(out) {}

int MainMenu::execut() const {
    while (true) {
        try {
            output.printMainMenu();
            return input.readMenuChoice();
        } catch (const std::exception&) {
            output.printError("Invalid input. Try again.\n");
        }
    }
}

FigureTypeMenu::FigureTypeMenu(const InputReader& in, const OutputPrinter& out) : input(in), output(out) {}

int FigureTypeMenu::execut() const {
    while (true) {
        try {
            output.printFigureTypeMenu();
            return input.readFigureMenuChoice();
        } catch (const std::exception&) {
            output.printError("Invalid input. Try again.\n");
        }
    }
}
