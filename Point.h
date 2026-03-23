#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double x;
        double y;
    public:
        Point(double x, double y);
        double getX() const;
        double getY() const;
        void setX(double x);// если set не используется, то убрать.
        void setY(double y);
};

#endif // POINT_H
