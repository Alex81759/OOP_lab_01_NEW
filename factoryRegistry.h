#ifndef FACTORYREGISTRY_H
#define FACTORYREGISTRY_H

#include <map>
#include <memory>
#include <typeindex>
#include "figureFactory.h"

class FactoryRegistry {
    private:
        std::map<std::type_index, std::unique_ptr<FigureFactory>> factories;
    public:
        FactoryRegistry();
        const FigureFactory& getFactory(const std::type_info& type) const;
};

#endif // FACTORYREGISTRY_H
