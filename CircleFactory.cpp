#include "CircleFactory.h"
#include "Circle.h"
#include <stdexcept>

std::unique_ptr<Figure> CircleFactory::create(const FigureParameters& params) const {
    const auto* circleParams = dynamic_cast<const CircleParameters*>(&params);
    if (circleParams == nullptr) {
        throw std::invalid_argument("CircleFactory error: wrong parameter type.");
    }

    return std::make_unique<Circle>(
        circleParams->name,
        circleParams->center,
        circleParams->radius
    );
}

FigureType CircleFactory::supportedType() const {
    return FigureType::Circle;
}
