#ifndef FIGUREPARAMETERS_H
#define FIGUREPARAMETERS_H

#include <string>
#include <typeinfo>
#include "point.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

class FigureParameters {
    private:
        std::string name;
    protected:
        explicit FigureParameters(std::string figureName) : name(std::move(figureName)) {}
    public:
        virtual ~FigureParameters() = default;
        virtual const std::type_info& getType() const = 0;
        const std::string& getName() const {
            return name;
        }
};

class CircleParameters : public FigureParameters {
    private:
        Point center;
        double radius;
    public:
        CircleParameters(std::string name, Point centerPoint, double circleRadius) : FigureParameters(std::move(name)), center(centerPoint), radius(circleRadius) {}
        const std::type_info& getType() const override {
            return typeid(Circle);
        }
        const Point& getCenter() const {
            return center;
        }
        double getRadius() const {
            return radius;
        }
};

class RectangleParameters : public FigureParameters {
    private:
        Point upperLeft;
        Point lowerRight;
    public:
        RectangleParameters(std::string name, Point upperLeftPoint, Point lowerRightPoint) : FigureParameters(std::move(name)), upperLeft(upperLeftPoint), lowerRight(lowerRightPoint) {}
        const std::type_info& getType() const override {
            return typeid(Rectangle);
        }
        const Point& getUpperLeft() const {
            return upperLeft;
        }
        const Point& getLowerRight() const {
            return lowerRight;
        }
};

class TriangleParameters : public FigureParameters {
    private:
        Point a;
        Point b;
        Point c;
    public:
        TriangleParameters(std::string name, Point pointA, Point pointB, Point pointC) : FigureParameters(std::move(name)), a(pointA), b(pointB), c(pointC) {}
        const std::type_info& getType() const override {
            return typeid(Triangle);
        }
        const Point& getA() const {
            return a;
        }
        const Point& getB() const {
            return b;
        }
        const Point& getC() const {
            return c;
        }
};

#endif // FIGUREPARAMETERS_H
