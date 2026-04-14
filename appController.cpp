#include "appController.h"

AppController::AppController() : mainMenu(input, output), figureMenu(input, output) {
    initActionHandlers();
    initFigureActionHandlers();
}

void AppController::initActionHandlers() {
    actionHandlers[MenuAction::MENU_ADD] = std::bind(&AppController::addFigure, this);
    actionHandlers[MenuAction::MENU_LIST_PARAMS] = std::bind(&AppController::listParams, this);
    actionHandlers[MenuAction::MENU_LIST_PERIMETER] = std::bind(&AppController::listPerimeter, this);
    actionHandlers[MenuAction::MENU_TOTAL_PERIMETER] = std::bind(&AppController::totalPerimeter, this);
    actionHandlers[MenuAction::MENU_SORT] = std::bind(&AppController::sortFigures, this);
    actionHandlers[MenuAction::MENU_REMOVE_BY_INDEX] = std::bind(&AppController::removeByIndex, this);
    actionHandlers[MenuAction::MENU_REMOVE_GREATER] = std::bind(&AppController::removeGreater, this);
}

void AppController::initFigureActionHandlers() {
    actionHandlersFigures[MenuFigureChoice::MENU_FIGURE_CRICLE] = std::bind(&AppController::createCircle, this);
    actionHandlersFigures[MenuFigureChoice::MENU_FIGURE_RECTANGLE] = std::bind(&AppController::createRectangle, this);
    actionHandlersFigures[MenuFigureChoice::MENU_FIGURE_TRIANGLE] = std::bind(&AppController::createTriangle, this);
}

void AppController::run() {
    while (true) {
        try {
            const int choice = mainMenu.execute(actionHandlers);
            const auto action = static_cast<MenuAction>(choice);
            if (action == MenuAction::MENU_EXIT) {
                break;
            }
            actionHandlers.at(action)();
        } catch (const std::exception& ex) {
            output.printError(ex.what());
        }
    }
}

void AppController::addFigure() {
    const int typeValue = figureMenu.execute(actionHandlersFigures);
    const auto choice = static_cast<MenuFigureChoice>(typeValue);
    actionHandlersFigures.at(choice)();
    output.printMessage("\nFigure added successfully.\n");
}

void AppController::listParams() {
    output.printFiguresWithParameters(collection);
}

void AppController::listPerimeter() {
    output.printFiguresWithPerimeter(collection);
}

void AppController::totalPerimeter() {
    output.printTotalPerimeter(collection.totalPerimeter());
}

void AppController::sortFigures() {
    collection.sortByPerimeterAscending();
    output.printMessage("\nSorted.\n");
}

void AppController::removeByIndex() {
    if (collection.size() == 0) {
        throw std::invalid_argument("\nNo figures in collection.\n");
    }
    const std::size_t index = input.readFigureIndex(collection.size());
    collection.removeByIndex(index);
    output.printMessage("\nRemoved.\n");
}

void AppController::removeGreater() {
    const double limit = input.readDouble("Enter perimeter limit: ");
    collection.removeWithPerimeterGreaterThan(limit);
    output.printMessage("\nRemoved figures with perimeter greater than limit.\n");
}

void AppController::createFigure(const std::type_info& type) {
    const auto parameters = input.readFigureParameters(type);
    const auto& factory = registry.getFactory(type);
    auto figure = factory.create(*parameters);
    collection.add(std::move(figure));
}

void AppController::createCircle() {
    createFigure(typeid(Circle));
}

void AppController::createRectangle() {
    createFigure(typeid(Rectangle));
}

void AppController::createTriangle() {
    createFigure(typeid(Triangle));
}
