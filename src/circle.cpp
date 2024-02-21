#include "circle.hpp"


Circle::Circle(Point center, std::string name, int radius) : Shape(center, name), radius(radius) {
}


double Circle::area() const
{
    return 3.14159 * radius * radius;
}

void Circle::draw(std::ostream& out) const 
{
    for (int y = -radius; y <= radius; y += 2) {
        for (int x = -radius; x <= radius; ++x) {
            out << (x * x + y * y <= radius * radius ? '*' : ' ');
        }
        out << '\n';
    }
}


Circle* Circle::clone() const {
    return new Circle(*this);
}
