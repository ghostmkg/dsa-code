#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() { cout << "Drawing Circle" << endl; }
};

class Square : public Shape {
public:
    void draw() { cout << "Drawing Square" << endl; }
};

class ShapeFactory {
public:
    Shape* createShape(string type) {
        if(type == "circle") return new Circle();
        if(type == "square") return new Square();
        return nullptr;
    }
};

int main() {
    ShapeFactory factory;
    Shape* s1 = factory.createShape("circle");
    s1->draw();
    Shape* s2 = factory.createShape("square");
    s2->draw();
    return 0;
}
