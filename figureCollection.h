#ifndef FIGURECOLLECTION_H
#define FIGURECOLLECTION_H

#include <vector>
#include <memory>
#include "figure.h"

class FigureCollection {
    private:
        std::vector<std::unique_ptr<Figure>> figures;
    public:
        void add(std::unique_ptr<Figure> figure);
        void removeByIndex(std::size_t index);
        void removeWithPerimeterGreaterThan(double limit);
        void sortByPerimeterAscending();
        double totalPerimeter() const;
        std::size_t size() const;
        const std::vector<std::unique_ptr<Figure>>& getAll() const;
};

#endif // FIGURECOLLECTION_H
