#include "rectangleFactory.h"
#include "rectangle.h"
#include <stdexcept>

std::unique_ptr<Figure> RectangleFactory::create(const FigureParameters& params) const {
    const auto* rectParams = dynamic_cast<const RectangleParameters*>(&params);
    if (rectParams == nullptr) {
        throw std::invalid_argument("\nError: wrong parameter type.\n");
    }
    return std::make_unique<Rectangle>(rectParams->getName(), rectParams->getUpperLeft(), rectParams->getLowerRight());
}
