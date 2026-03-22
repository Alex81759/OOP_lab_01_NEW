#include "AppController.h"
#include <stdexcept>

namespace {
    constexpr int MENU_EXIT = 0;
    constexpr int MENU_ADD = 1;
    constexpr int MENU_LIST_PARAMS = 2;
    constexpr int MENU_LIST_PERIMETER = 3;
    constexpr int MENU_TOTAL_PERIMETER = 4;
    constexpr int MENU_SORT = 5;
    constexpr int MENU_REMOVE_BY_INDEX = 6;
    constexpr int MENU_REMOVE_GREATER = 7;
}

void AppController::run() {
    bool running = true;
    while (running) {
        try {
            output.printMainMenu();
            const int choice = input.readMenuChoice(0, 7);
            processMenuChoice(choice, running);
        } catch (const std::exception& ex) {
            output.printError(ex.what());
        }
    }
}

void AppController::processMenuChoice(int choice, bool& running) { // убрать раннинг и сделать черезе словарь словарь, который будет в appcontroller/h
    if (choice == MENU_EXIT) {
        running = false;
    } else if (choice == MENU_ADD) {
        addFigure();
    } else if (choice == MENU_LIST_PARAMS) {
        output.printFiguresWithParameters(collection);
    } else if (choice == MENU_LIST_PERIMETER) {
        output.printFiguresWithPerimeter(collection);
    } else if (choice == MENU_TOTAL_PERIMETER) {
        output.printTotalPerimeter(collection.totalPerimeter());
    } else if (choice == MENU_SORT) {
        collection.sortByPerimeterAscending();
        output.printMessage("Sorted.");
    } else if (choice == MENU_REMOVE_BY_INDEX) {
        const std::size_t index = input.readFigureIndex(collection.size());
        collection.removeByIndex(index);
        output.printMessage("Removed.");
    } else if (choice == MENU_REMOVE_GREATER) {
        const double limit = input.readDouble("Enter perimeter limit: ");
        collection.removeWithPerimeterGreaterThan(limit);
        output.printMessage("Removed figures with perimeter greater than limit.");
    }
}

void AppController::addFigure() {
    output.printFigureTypeMenu();
    const int typeValue = input.readFigureTypeChoice();
    const FigureType type = static_cast<FigureType>(typeValue);
    const auto params = input.readFigureParameters(type);
    const auto& factory = registry.getFactory(type);
    auto figure = factory.create(*params);
    collection.add(std::move(figure));
    output.printMessage("Figure added successfully.");
}
