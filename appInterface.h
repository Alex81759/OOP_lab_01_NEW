#ifndef INTERFACE_H
#define INTERFACE_H

#include "inputReader.h"
#include "outputPrinter.h"

class Menu {
    public:
        virtual ~Menu() = default;
        virtual int execut() const = 0;
};

class MainMenu : public Menu {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        MainMenu(const InputReader& in, const OutputPrinter& out);
        int execut() const override;
};

class FigureTypeMenu : public Menu {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        FigureTypeMenu(const InputReader& in, const OutputPrinter& out);
        int execut() const override;
};

#endif // INTERFACE_H
