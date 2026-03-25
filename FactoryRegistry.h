#ifndef FACTORYREGISTRY_H
#define FACTORYREGISTRY_H

#include <map>
#include <memory>
#include "FigureFactory.h"

class FactoryRegistry {
    private:
        std::map<std::type_info, std::unique_ptr<FigureFactory>> factories;
    public:
        FactoryRegistry();
        const FigureFactory& getFactory(std::type_info type) const;
};

#endif // FACTORYREGISTRY_H
