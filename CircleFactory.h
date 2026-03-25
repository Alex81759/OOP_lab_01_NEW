#ifndef CIRCLEFACTORY_H
#define CIRCLEFACTORY_H

#include "FigureFactory.h"

class CircleFactory : public FigureFactory {
    public:
        std::unique_ptr<Figure> create(const FigureParameters& params) const override;
};

#endif // CIRCLEFACTORY_H
