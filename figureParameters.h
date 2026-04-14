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
        explicit FigureParameters(const std::string& figureName) : name(figureName) {}
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
        CircleParameters(const std::string& name, const Point& centerPoint, double circleRadius) : FigureParameters(name), center(centerPoint), radius(circleRadius) {}
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
        RectangleParameters(const std::string& name, const Point& upperLeftPoint, const Point& lowerRightPoint) : FigureParameters(name), upperLeft(upperLeftPoint), lowerRight(lowerRightPoint) {}
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
        TriangleParameters(const std::string& name, const Point& pointA, const Point& pointB, const Point& pointC) : FigureParameters(name), a(pointA), b(pointB), c(pointC) {}
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
