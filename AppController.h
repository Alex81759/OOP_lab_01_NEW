#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include "FactoryRegistry.h"
#include "FigureCollection.h"
#include "InputReader.h"
#include "OutputPrinter.h"
// добавить отступ во всех классах и сначала private protected public
// убрать все подчеркивания в именах
class AppController {
public:
    void run();
private:
    /* вместо namespace {
    constexpr int MENU_EXIT = 0;
    constexpr int MENU_ADD = 1;
    constexpr int MENU_LIST_PARAMS = 2;
    constexpr int MENU_LIST_PERIMETER = 3;
    constexpr int MENU_TOTAL_PERIMETER = 4;
    constexpr int MENU_SORT = 5;
    constexpr int MENU_REMOVE_BY_INDEX = 6;
    constexpr int MENU_REMOVE_GREATER = 7;
    добавить enum именной MenuStatus*/

    void processMenuChoice(int choice, bool& running);// убрать running

    void addFigure();
    FactoryRegistry registry;
    FigureCollection collection;
    InputReader input;
    OutputPrinter output;
};

#endif // APPCONTROLLER_H
