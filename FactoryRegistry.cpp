#include "FactoryRegistry.h"
#include "CircleFactory.h"
#include "RectangleFactory.h"
#include "TriangleFactory.h"
#include <stdexcept>

FactoryRegistry::FactoryRegistry() {
    auto circleFactory = std::make_unique<CircleFactory>();
    factories[typeid(Circle).name()] = std::move(circleFactory);
    auto rectangleFactory = std::make_unique<RectangleFactory>();
    factories[typeid(Circle).name()] = std::move(rectangleFactory);
    auto triangleFactory = std::make_unique<TriangleFactory>();
    factories[typeid(Circle).name()] = std::move(triangleFactory);
}

const FigureFactory& FactoryRegistry::getFactory(FigureType type) const {
    const auto it = factories.find(type);
    if (it == factories.end()) {
        throw std::invalid_argument("FactoryRegistry error: unknown figure type.");
    }
    return *(it->second);//
}
