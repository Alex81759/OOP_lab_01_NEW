#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <memory>
#include <string>
#include <iostream>
#include <stdexcept>
#include "figureParameters.h"

class InputReader {
    private:
        const int minMenuValue = 0;
        const int minFigureMenuValue = 1;
        const int maxMenuValue = 7;
        const int maxFigureMenuValue = 3;
        void clearInput() const;
        Point readPoint(const std::string& text) const;
    public:
        template <typename T>
        int readMenuChoice(const T& actionHandlers) const {
            int value = 0;
            std::cout << "Choose menu item: ";
            std::cin >> value;
            try {
                using Action = typename T::key_type;
                const Action action = static_cast<Action>(value);
                actionHandlers.at(action);
            } catch (const std::out_of_range&) {
                clearInput();
                throw std::runtime_error("Invalid input. Try again.\n");
            }
            clearInput();
            return value;
        }
        std::size_t readFigureIndex(std::size_t maxIndex) const;
        double readDouble(const std::string& text) const;
        std::string readNonEmptyString(const std::string& text) const;
        std::unique_ptr<FigureParameters> readFigureParameters(const std::type_info&  type) const;
};

#endif // INPUTREADER_H
