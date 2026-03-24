#include "AppController.h"
#include <stdexcept>

AppController::AppController() {
    actionHandlers[MenuAction::MENU_ADD] = [this] () {addFigure();};
    actionHandlers[MenuAction::MENU_LIST_PARAMS] = [this] () {output.printFiguresWithParameters(collection); };
    actionHandlers[MenuAction::MENU_LIST_PERIMETER] = [this] () {output.printFiguresWithPerimeter(collection);};
    actionHandlers[MenuAction::MENU_TOTAL_PERIMETER] = [this] () {output.printTotalPerimeter(collection.totalPerimeter());};
    actionHandlers[MenuAction::MENU_SORT] = [this] () {collection.sortByPerimeterAscending(); output.printMessage("Sorted.");};
    actionHandlers[MenuAction::MENU_REMOVE_BY_INDEX] = [this] () {const std::size_t index = input.readFigureIndex(collection.size()); collection.removeByIndex(index); output.printMessage("Removed.");};
    actionHandlers[MenuAction::MENU_REMOVE_GREATER] = [this] () {const double limit = input.readDouble("Enter perimeter limit: "); collection.removeWithPerimeterGreaterThan(limit); output.printMessage("Removed figures with perimeter greater than limit.");};
}

void AppController::run() {
    bool isRunning = true;
    while (isRunning) {
        try {
            output.printMainMenu();
            const int choice = input.readMenuChoice();
            isRunning = processMenuChoice(choice);
        } catch (const std::exception& ex) {
            output.printError(ex.what());
        }
    }
}

bool AppController::processMenuChoice(int choice) {
    const auto action = static_cast<MenuAction>(choice);
    bool result = true;
    if (action == MenuAction::MENU_EXIT) {
        result = false;
    } else {
        const auto it = actionHandlers.find(action);
        if (it == actionHandlers.end()) {
            throw std::invalid_argument("Unknown menu action.");
        }
        it->second();
    }
    return result;
}

void AppController::addFigure() {
    output.printFigureTypeMenu();
    const int typeValue = input.readFigureTypeChoice();
    const FigureType type = static_cast<FigureType>(typeValue);
    const auto parameters = input.readFigureParameters(type);
    const auto& factory = registry.getFactory(type);
    auto figure = factory.create(*parameters);
    collection.add(std::move(figure));
    output.printMessage("Figure added successfully.");
}
