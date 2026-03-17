#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
public:
    Figure(std::string name);
    virtual ~Figure() = default;
    const std::string& getName() const;
    virtual std::string getType() const = 0;//производные классы обязательно переопределить этот метод,
    virtual double perimeter() const = 0;
    virtual std::string parametersToString() const = 0;
protected:
    std::string name_;//
};

#endif // FIGURE_H
