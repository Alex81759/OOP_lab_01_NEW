#ifndef INTERFACE_H
#define INTERFACE_H

#include "inputReader.h"
#include "outputPrinter.h"

class Interface {
    public:
        virtual ~Interface() = default;
        virtual int readAndChoice() const = 0;
};

class MainMenuInterface : public Interface {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        MainMenuInterface(const InputReader& in, const OutputPrinter& out);
        int readAndChoice() const override;
};

class FigureTypeMenuInterface : public Interface {
    private:
        const InputReader& input;
        const OutputPrinter& output;
    public:
        FigureTypeMenuInterface(const InputReader& in, const OutputPrinter& out);
        int readAndChoice() const override;
};

#endif // INTERFACE_H
