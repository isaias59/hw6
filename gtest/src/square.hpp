#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square(Point center, std::string name, int side);

    Square* clone() const override;
};

#endif
