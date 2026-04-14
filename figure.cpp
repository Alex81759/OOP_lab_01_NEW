#include "figure.h"

Figure::Figure(const std::string& name) : name(name) {}

const std::string& Figure::getName() const {
    return name;
}
