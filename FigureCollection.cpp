#include "FigureCollection.h"
#include <algorithm>
#include <stdexcept>

void FigureCollection::add(std::unique_ptr<Figure> figure) {
    if (!figure) {
        throw std::invalid_argument("Collection error: null figure.");
    }
    figures_.push_back(std::move(figure));
}

void FigureCollection::removeByIndex(std::size_t index) {
    if (index >= figures_.size()) {
        throw std::out_of_range("Collection error: index out of range.");
    }
    figures_.erase(figures_.begin() + static_cast<long>(index));
}

void FigureCollection::removeWithPerimeterGreaterThan(double limit) {
    figures_.erase(
        std::remove_if(figures_.begin(), figures_.end(),
                       [limit](const std::unique_ptr<Figure>& figure) {
                           return figure->perimeter() > limit;
                       }),
        figures_.end()
        );
}

void FigureCollection::sortByPerimeterAscending() {
    std::sort(figures_.begin(), figures_.end(),
              [](const std::unique_ptr<Figure>& left, const std::unique_ptr<Figure>& right) {
                  return left->perimeter() < right->perimeter();
              });
}

double FigureCollection::totalPerimeter() const {
    double sum = 0.0;
    for (const auto& figure : figures_) {
        sum += figure->perimeter();
    }
    return sum;
}

std::size_t FigureCollection::size() const {
    return figures_.size();
}

const std::vector<std::unique_ptr<Figure>>& FigureCollection::getAll() const {
    return figures_;
}
