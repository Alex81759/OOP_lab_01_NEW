#ifndef FACTORYREGISTRY_H
#define FACTORYREGISTRY_H

#include <map>
#include <memory>
#include "FigureFactory.h"

class FactoryRegistry {
    private:
        std::map<FigureType, std::unique_ptr<FigureFactory>> factories;
    public:
        FactoryRegistry();
        const FigureFactory& getFactory(FigureType type) const;
};

#endif // FACTORYREGISTRY_H
