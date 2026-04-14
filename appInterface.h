#ifndef INTERFACE_H
#define INTERFACE_H

#include <exception>
#include "inputReader.h"
#include "outputPrinter.h"

class Menu {
    public:
        virtual ~Menu() = default;
};

class MainMenu : public Menu {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        MainMenu(const InputReader& in, const OutputPrinter& out);
        template <typename T>
        int execute(const T& actionHandlers) const {
            while (true) {
                try {
                    output.printMainMenu();
                    return input.readMenuChoice(actionHandlers);
                } catch (const std::exception&) {
                    output.printError("Invalid input. Try again.\n");
                }
            }
        }
};

class FigureTypeMenu : public Menu {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        FigureTypeMenu(const InputReader& in, const OutputPrinter& out);
        template <typename T>
        int execute(const T& actionHandlersFigures) const {
            while (true) {
                try {
                    output.printFigureTypeMenu();
                    return input.readMenuChoice(actionHandlersFigures);
                } catch (const std::exception&) {
                    output.printError("Invalid input. Try again.\n");
                }
            }
        }
};

#endif // INTERFACE_H
