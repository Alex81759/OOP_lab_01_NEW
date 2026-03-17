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
public:
    std::string name;
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
    std::string name;
    Point a{};
    Point b{};
    Point c{};

    FigureType getType() const override {
        return FigureType::Triangle;
    }
};

#endif // FIGUREPARAMETERS_H
