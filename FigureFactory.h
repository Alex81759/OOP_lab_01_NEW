#ifndef FIGUREFACTORY_H
#define FIGUREFACTORY_H

#include <memory>
#include "Figure.h"
#include "FigureParameters.h"

class FigureFactory {
    public:
        virtual ~FigureFactory() = default;
        virtual std::unique_ptr<Figure> create(const FigureParameters& params) const = 0;
};

#endif // FIGUREFACTORY_H
