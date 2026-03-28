#include "circleFactory.h"
#include "circle.h"
#include <stdexcept>

std::unique_ptr<Figure> CircleFactory::create(const FigureParameters& params) const {
    const auto* circleParams = dynamic_cast<const CircleParameters*>(&params);
    if (circleParams == nullptr) {
        throw std::invalid_argument("\nError: wrong parameter type.\n");
    }
    return std::make_unique<Circle>(circleParams->getName(), circleParams->getCenter(), circleParams->getRadius());
}
