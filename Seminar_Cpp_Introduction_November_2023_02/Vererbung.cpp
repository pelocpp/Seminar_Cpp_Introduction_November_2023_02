#include <iostream>

// UI für graphische Figuren

class IRectangle
{
public:
    virtual void draw() = 0;
    virtual void eraseBackground() = 0;
    virtual void drawBorder() = 0;
};

// ====================================================

class Rectangle : public IRectangle  // , ICloneable, IComparable
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
    // KEIN VIRTUAL
    // KEIN VERDECKEN

    void eraseBackground()
    {
        std::cout << "  Rectangle::ERASEBackground" << std::endl;
    }

    virtual void drawBorder() = 0;   // abstract // keine Realisierung


public:
    virtual void draw() {

        // Grundlegendes

        std::cout
            << "  Rectangle::draw [x=" << m_x
            << ", y=" << m_y << "]" << std::endl;

        eraseBackground();

        drawBorder();
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

    void draw() {
        std::cout << "ColoredRectangle::draw" << std::endl;

        //std::cout
        //    << "  [x=" << getX()
        //    << ", y=" << getY() << "]" << std::endl;

        // Wiederverwendung:
        Rectangle::draw();

        std::cout << "  ColoredRectangle malt seinen farbigen Anteil" << std::endl;
    }

    void drawBorder()
    {
        std::cout << "  ColoredRectangle malt seinen RAND" << std::endl;
    }
};

class TransparentRectangle : public Rectangle
{
private:
    double m_opaque;  // representing some transparency model

public:
    // c'tor(s)
    TransparentRectangle()
        : TransparentRectangle(0, 0, 0, 0, 0.0)
    {}

    TransparentRectangle(int x, int y, int width, int height, double transparency)
        : Rectangle(x, y, width, height), m_opaque(transparency)
    {}

    void draw() override {
        std::cout << "TransparentRectangle::draw" << std::endl;

        // Wiederverwendung:
        Rectangle::draw();

        std::cout << "  TransparentRectangle malt seinen farbigen Anteil" << std::endl;
    }

    void drawBorder()
    {
        std::cout << "  TransparentRectangle malt seinen RAND" << std::endl;
    }
};



void test_inheritance_01()
{
    //Rectangle r(1, 1, 20, 40);
    //r.draw();

    ColoredRectangle cr(2, 2, 30, 60, 88);
    cr.draw();
}

void test_inheritance_02()
{
    Rectangle* r;

    ColoredRectangle cr(2, 2, 30, 60, 88);

    r = & cr;  // is-a Beziehung

    r->draw();  // A) r ist Pointer auf Rectangle:
                //    ==> Aufruf von Rectangle::draw
                // B) r zeigt auf ein Objekt des Types ColoredRectangle:
                //    ==> Aufruf von ColoredRectangle::draw
}

void test_inheritance_03()
{
    ColoredRectangle cr1(2, 2, 30, 60, 88);
    ColoredRectangle cr2(1, 1, 20, 20, 88);

    TransparentRectangle tr1(3, 3, 60, 80, 44.44);
    TransparentRectangle tr2(4, 4, 60, 90, 44.44);
    TransparentRectangle tr3(5, 5, 60, 70, 44.44);

    // =====================================

    IRectangle* rectangles[5]{ &cr1, &tr1, &cr2, &tr2, &tr3 };

    for (int i = 0; i < 5; ++i) {

        rectangles[i]->draw();

        //if (rectangles[i] ist Typ ColoredRectangle) {
        //    Methode von ColoredRectangle;
        //}
        //else   if (rectangles[i] ist Typ TransparentRectangle) {
        //    Methode von TransparentRectangle;
        //}
    }
}


void test_inheritance()
{
    test_inheritance_03();
}

