#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "FactoryRegistry.h"
#include "FigureCollection.h"
#include "InputReader.h"
#include "OutputPrinter.h"

//codestyle c/c++

class AppController {
public:
    void run();
private:
    void processMenuChoice(int choice, bool& running);
    //состояние "запущено/не запущено" полностью контролируется GUI, а не C-ядром.
    void addFigure();
    FactoryRegistry registry;
    FigureCollection collection;
    InputReader input;
    OutputPrinter output;
};

#endif // APPCONTROLLER_H
