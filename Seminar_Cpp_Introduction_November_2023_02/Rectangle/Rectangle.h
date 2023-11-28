// ===============================================================================
// Rectangle.h
// ===============================================================================

#pragma once

#include <iostream>

#include "Point.h"

namespace Rectangle {

    class Rectangle
    {
    private:
        double m_x;
        double m_y;
        double m_width;
        double m_height;

    public:

        // "öffentliche Schnittstelle" / public interface: Ist ALLES, was public ist

        // c'tors
        Rectangle();
        Rectangle(double x, double left, double width, double height);

        static void tueWas () {}

        // getter/setter
        double getX() const;
        double getY() const;
        double getWidth() const;
        double getHeight() const;

        void setX(double x);
        void setY(double y);
        void setWidth(double width);
        void setHeight(double height);

        // public interface // methods
        double circumference() const;
        double diagonal() const;
        double area() const;
        bool isSquare() const;
        void moveTo(double, double);
        bool equals(const Rectangle& other) const;
        Point center() const;
        Rectangle intersection(const Rectangle& other) const;
        void print() const;

        // private helper methods
    private:
        void helper() {}
    };
}

// ===============================================================================
// End-of-File
// ===============================================================================
