#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "FigureFactory.h"

class RectangleFactory : public FigureFactory {
    public:
        std::unique_ptr<Figure> create(const FigureParameters& params) const override;
        FigureType supportedType() const override;
};

#endif // RECTANGLEFACTORY_H
