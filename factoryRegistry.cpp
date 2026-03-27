#include "factoryRegistry.h"
#include "circleFactory.h"
#include "rectangleFactory.h"
#include "triangleFactory.h"
#include <stdexcept>

FactoryRegistry::FactoryRegistry() {
    auto circleFactory = std::make_unique<CircleFactory>();
    factories[typeid(Circle)] = std::move(circleFactory);
    auto rectangleFactory = std::make_unique<RectangleFactory>();
    factories[typeid(Rectangle)] = std::move(rectangleFactory);
    auto triangleFactory = std::make_unique<TriangleFactory>();
    factories[typeid(Triangle)] = std::move(triangleFactory);
}

const FigureFactory& FactoryRegistry::getFactory(const std::type_info& type) const {
    const auto it = factories.find(type);
    if (it == factories.end()) {
        throw std::invalid_argument("Error: unknown figure type.");
    }
    return *it->second;
}
