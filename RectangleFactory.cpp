#include "RectangleFactory.h"
#include "Rectangle.h"
#include <stdexcept>

std::unique_ptr<Figure> RectangleFactory::create(const FigureParameters& params) const {
    const auto* rectParams = dynamic_cast<const RectangleParameters*>(&params);
    if (rectParams == nullptr) {
        throw std::invalid_argument("RectangleFactory error: wrong parameter type.");
    }

    return std::make_unique<Rectangle>(
        rectParams->name,
        rectParams->upperLeft,
        rectParams->lowerRight
        );  //
}

FigureType RectangleFactory::supportedType() const {
    return FigureType::Rectangle;
}
