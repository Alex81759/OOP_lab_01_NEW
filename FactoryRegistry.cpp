#include "FactoryRegistry.h"
#include "CircleFactory.h"
#include "RectangleFactory.h"
#include "TriangleFactory.h"
#include <stdexcept>

FactoryRegistry::FactoryRegistry() {// сделать по id класса
    factories_[FigureType::Circle] = std::make_unique<CircleFactory>();
    factories_[FigureType::Rectangle] = std::make_unique<RectangleFactory>();
    factories_[FigureType::Triangle] = std::make_unique<TriangleFactory>();
}

const FigureFactory& FactoryRegistry::getFactory(FigureType type) const {
    const auto it = factories_.find(type);
    if (it == factories_.end()) {
        throw std::invalid_argument("FactoryRegistry error: unknown figure type.");
    }
    return *(it->second);
}
