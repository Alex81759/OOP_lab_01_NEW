#include "TriangleFactory.h"
#include "Triangle.h"
#include <stdexcept>

std::unique_ptr<Figure> TriangleFactory::create(const FigureParameters& params) const {
    const auto* triangleParams = dynamic_cast<const TriangleParameters*>(&params);
    if (triangleParams == nullptr) {
        throw std::invalid_argument("TriangleFactory error: wrong parameter type.");
    }
    return std::make_unique<Triangle>(
        triangleParams->name,
        triangleParams->a,
        triangleParams->b,
        triangleParams->c
        );
}

FigureType TriangleFactory::supportedType() const {
    return FigureType::Triangle;
}
