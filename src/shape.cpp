#include "shape.hpp"

Shape::Shape(Point center, std::string name) : center(center), name(name) {
    // Constructor implementation goes here
}
//
void Shape::print(std::ostream& out) const
{
    out << name << "(" << center.x << ", " << center.y << ")" << '\n';

}
