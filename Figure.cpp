#include "Figure.h"
#include <utility>

Figure::Figure(std::string name) : name(std::move(name)) {}

const std::string& Figure::getName() const {
    return name;
}
