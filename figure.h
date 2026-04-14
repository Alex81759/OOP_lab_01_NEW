#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <typeinfo>

class Figure {
    protected:
        std::string name;
    public:
        Figure(const std::string& name);
        virtual ~Figure() = default;
        const std::string& getName() const;
        virtual const std::type_info& getType() const = 0;
        virtual double perimeter() const = 0;
        virtual std::string parametersToString() const = 0;
};

#endif // FIGURE_H
