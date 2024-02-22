#include "rectangle.hpp"

Rectangle::Rectangle(Point center, std::string name, int width, int height)
    : Shape(center, name), width(width), height(height) {}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::draw(std::ostream& out) const {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            out << '*';
        }
        out << '\n';
    }
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}
