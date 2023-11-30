#include <iostream>

class Rectangle
{
private:
    int m_x;
    int m_y;
    int m_width;
    int m_height;

protected:
    // ist zu entscheiden 

public:
    // c'tor(s)
    Rectangle() : Rectangle(0, 0, 0, 0) {}

    Rectangle(int x, int y, int width, int height)
        : m_x(x), m_y(y), m_width(width), m_height(height)
    {}

    // getter
    int getX() { return m_x; }
    int getY() { return m_y; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

    // public interface
    //void eraseBackground()
    //{
    //    std::cout << "  Rectangle::eraseBackground" << std::endl;
    //}

public:
    void draw() {

        std::cout
            << "Rectangle::draw [x=" << m_x
            << ", y=" << m_y << "]" << std::endl;

        // eraseBackground();
    }
};

class ColoredRectangle : public Rectangle
{
private:
    int m_color;

public:
    ColoredRectangle(int x, int y, int width, int height, int color)
        : Rectangle (x, y, width, height), m_color (color)
    {}

    // Verdecken
    void draw() {
        std::cout << "ColoredRectangle::draw" << std::endl;

        std::cout
            << "  [x=" << getX()
            << ", y=" << getY() << "]" << std::endl;

        //std::cout
        //    << "  [x=" << m_x
        //    << ", y=" << m_y << "]" << std::endl;

        // Wiederverwendung:
       // Rectangle::draw();
    }
};


void test_inheritance()
{
    Rectangle r(1, 1, 20, 40);
    r.draw();

    // AUßerhalb der Klasse
    // r.m_x = -1;   // NEIN, dies soll NIEMALS GEHEN

    ColoredRectangle cr(2, 2, 30, 60, 88);
    cr.draw();
}
