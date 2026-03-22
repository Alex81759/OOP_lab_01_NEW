#ifndef FIGUREPARAMETERS_H
#define FIGUREPARAMETERS_H

#include <string>
#include "Point.h"
#include "FigureType.h"

class FigureParameters {
public:
    virtual ~FigureParameters() = default;
    virtual FigureType getType() const = 0;
};

class CircleParameters : public FigureParameters {
private: // во всех таких классах сделать поля приватные
    std::string name;// все имена по ссылке
    Point center{};
    double radius = 0.0;
    FigureType getType() const override {
        return FigureType::Circle;
    }
};

class RectangleParameters : public FigureParameters {
public:
    std::string name;
    Point upperLeft{};
    Point lowerRight{};

    FigureType getType() const override {
        return FigureType::Rectangle;
    }
};

class TriangleParameters : public FigureParameters {
public:
    std::string name;// через ссылку
    Point a{};
    Point b{};// зачем инициализировать так??
    Point c{};// добавить get

    FigureType getType() const override {
        return FigureType::Triangle;
    }
};

#endif // FIGUREPARAMETERS_H
