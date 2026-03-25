#include "AppController.h"
#include <stdexcept>

AppController::AppController() {
    actionHandlers[MenuAction::MENU_ADD] = std::bind(&AppController::addFigure, this);
    actionHandlers[MenuAction::MENU_LIST_PARAMS] = std::bind(&AppController::listParams, this);
    actionHandlers[MenuAction::MENU_LIST_PERIMETER] = std::bind(&AppController::listPerimeter, this);
    actionHandlers[MenuAction::MENU_TOTAL_PERIMETER] = std::bind(&AppController::totalPerimeter, this);
    actionHandlers[MenuAction::MENU_SORT] = std::bind(&AppController::sortFigures, this);
    actionHandlers[MenuAction::MENU_REMOVE_BY_INDEX] = std::bind(&AppController::removeByIndex, this);
    actionHandlers[MenuAction::MENU_REMOVE_GREATER] = std::bind(&AppController::removeGreater, this);
}

void AppController::run() {
    bool isRunning = true;
    while (isRunning) {
        try {
            output.printMainMenu();
            const int choice = input.readMenuChoice();
            const auto action = static_cast<MenuAction>(choice);
            isRunning = processMenuChoice(action);
        } catch (const std::exception& ex) {
            output.printError(ex.what());
        }
    }
}

bool AppController::processMenuChoice(MenuAction action) {
    bool result = true;
    if (action == MenuAction::MENU_EXIT) {
        result = false;
    } else {
        const auto it = actionHandlers[action];
        if (it != NULL) {
            throw std::invalid_argument("Unknown menu action.");
        }
        it();
    }
    return result;
}

void AppController::addFigure() {
    output.printFigureTypeMenu();
    const int typeValue = input.readFigureTypeChoice();
    const FigureType type = static_cast<FigureType>(typeValue);...
    const auto parameters = input.readFigureParameters(type);
    const auto& factory = registry.getFactory(type);
    auto figure = factory.create(*parameters);
    collection.add(std::move(figure));
    output.printMessage("Figure added successfully.");
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
    output.printMessage("Sorted.");
}

void AppController::removeByIndex() {
    const std::size_t index = input.readFigureIndex(collection.size());
    collection.removeByIndex(index);
    output.printMessage("Removed.");
}

void AppController::removeGreater() {
    const double limit = input.readDouble("Enter perimeter limit: ");
    collection.removeWithPerimeterGreaterThan(limit);
    output.printMessage("Removed figures with perimeter greater than limit.");
}
