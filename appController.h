#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <functional>
#include <map>
#include "factoryRegistry.h"
#include "figureCollection.h"
#include "inputReader.h"
#include "outputPrinter.h"
#include "appInterface.h"

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
        enum class MenuFigureChoice{
            MENU_FIGURE_CRICLE = 1,
            MENU_FIGURE_RECTANGLE,
            MENU_FIGURE_TRIANGLE
        };
        void addFigure();
        void listParams();
        void removeGreater();
        void listPerimeter();
        void totalPerimeter();
        void sortFigures();
        void removeByIndex();
        void createFigure(const std::type_info& type);
        void createCircle();
        void createRectangle();
        void createTriangle();
        FactoryRegistry registry;
        FigureCollection collection;
        InputReader input;
        OutputPrinter output;
        MainMenuInterface mainMenu;
        FigureTypeMenuInterface figureMenu;
        std::map<MenuAction, std::function<void()>> actionHandlers;
        std::map<MenuFigureChoice, std::function<void()>> actionHandlersFigures;
    public:
        AppController();
        void run();
};

#endif // APPCONTROLLER_H
