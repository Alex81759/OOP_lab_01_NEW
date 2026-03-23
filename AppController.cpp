#include "AppController.h"
#include <stdexcept>

AppController::AppController() {
    actionHandlers[MenuAction::Add] = [this]() { addFigure(); };
    actionHandlers[MenuAction::ListWithParameters] = [this]() { output.printFiguresWithParameters(collection); };
    actionHandlers[MenuAction::ListWithPerimeter] = [this]() { output.printFiguresWithPerimeter(collection); };
    actionHandlers[MenuAction::TotalPerimeter] = [this]() { output.printTotalPerimeter(collection.totalPerimeter()); };
    actionHandlers[MenuAction::SortAscending] = [this]() {
        collection.sortByPerimeterAscending();
        output.printMessage("Sorted.");
    };
    actionHandlers[MenuAction::RemoveByIndex] = [this]() {
        const std::size_t index = input.readFigureIndex(collection.size());
        collection.removeByIndex(index);
        output.printMessage("Removed.");
    };
    actionHandlers[MenuAction::RemoveWithPerimeterGreater] = [this]() {
        const double limit = input.readDouble("Enter perimeter limit: ");
        collection.removeWithPerimeterGreaterThan(limit);
        output.printMessage("Removed figures with perimeter greater than limit.");
    };
}

void AppController::run() {
    bool isRunning = true;
    while (isRunning) {
        try {
            output.printMainMenu();
            const int choice = input.readMenuChoice(0, 7);
            isRunning = processMenuChoice(choice);
        } catch (const std::exception& ex) {
            output.printError(ex.what());
        }
    }
}

bool AppController::processMenuChoice(int choice) {
    const auto action = static_cast<MenuAction>(choice);

    if (action == MenuAction::Exit) {
        return false;
    }

    const auto it = actionHandlers.find(action);
    if (it == actionHandlers.end()) {
        throw std::invalid_argument("Unknown menu action.");
    }

    it->second();
    return true;
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
