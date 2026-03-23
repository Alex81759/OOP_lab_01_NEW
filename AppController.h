#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <functional>
#include <map>
#include "FactoryRegistry.h"
#include "FigureCollection.h"
#include "InputReader.h"
#include "OutputPrinter.h"

class AppController {
    private:
        enum class MenuAction {
            MENU_EXIT,
            MENU_ADD,
            MENU_LIST_PARAMS,
            MENU_LIST_PERIMETER,
            MENU_TOTAL_PERIMETER,
            MENU_SORT,
            MENU_REMOVE_BY_INDEX,
            MENU_REMOVE_GREATER
        };
        bool processMenuChoice(int choice);
        void addFigure();
        FactoryRegistry registry;
        FigureCollection collection;
        InputReader input;
        OutputPrinter output;
        //using ActionHandler = std::function<void()>;
        std::map<MenuAction, std::function<void()>> actionHandlers;
    public:
        AppController();
        void run();
};

#endif // APPCONTROLLER_H
