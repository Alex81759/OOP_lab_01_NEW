#ifndef TRIANGLEFACTORY_H
#define TRIANGLEFACTORY_H

#include "figureFactory.h"

class TriangleFactory : public FigureFactory {
    public:
        std::unique_ptr<Figure> create(const FigureParameters& params) const override;
};

#endif // TRIANGLEFACTORY_H
