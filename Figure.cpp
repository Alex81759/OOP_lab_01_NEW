#include "Figure.h"
#include <utility>

Figure::Figure(std::string name) : name_(std::move(name)) {}

const std::string& Figure::getName() const {
    return name_;
}
