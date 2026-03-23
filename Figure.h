#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
    protected:
        std::string name;
    public:
        Figure(std::string name);
        virtual ~Figure() = default;
        const std::string& getName() const;
        const std::string& getType() const;
        virtual double perimeter() const = 0;
        virtual std::string parametersToString() const = 0;
};

#endif // FIGURE_H
