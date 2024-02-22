#include <gtest/gtest.h>
#include <sstream>

#include "circle.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "square.hpp"
#include "triangle.hpp"

TEST(CircleTests, Area) {
    EXPECT_NEAR(Circle({1, 2}, "", 3).area(), 28.27, 0.01);
}

TEST(CircleTests, Draw) {
    Circle c{{5, 10}, "circle", 3};

    std::stringstream out;
    c.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "   *   \n"
                 " ***** \n"
                 " ***** \n"
                 "   *   \n");
}

TEST(CircleTests, Clone) {
    Circle c{{3, 2}, "foo", 10};

    Circle* clone = c.clone();
    delete clone;
}

TEST(CircleTests, Print) {
    Circle c{{3, 2}, "foo", 10};

    std::stringstream out;
    c.print(out);

    EXPECT_STREQ(out.str().c_str(), "foo(3, 2)\n");
}

// Rectangle Tests
TEST(RectangleTests, Area) {
    EXPECT_EQ(Rectangle({0, 0}, "rect", 4, 3).area(), 12); // Assuming width = 4 and height = 3
}

TEST(RectangleTests, Draw) {
    Rectangle r{{0, 0}, "rectangle", 5, 3}; // Assuming width = 5 and height = 3

    std::stringstream out;
    r.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "*****\n"
                 "*****\n"
                 "*****\n");
}

TEST(RectangleTests, Clone) {
    Rectangle r{{3, 2}, "rect", 6, 4}; // Assuming width = 6 and height = 4

    Rectangle* clone = r.clone();
    delete clone;
}

TEST(RectangleTests, Print) {
    Rectangle r{{3, 2}, "rect", 6, 4}; // Assuming width = 6 and height = 4

    std::stringstream out;
    r.print(out);

    EXPECT_STREQ(out.str().c_str(), "rect(3, 2)\n");
}

// Square Tests
TEST(SquareTests, Area) {
    EXPECT_EQ(Square({0, 0}, "square", 5).area(), 25); // Assuming side length = 5
}

TEST(SquareTests, Draw) {
    Square s{{0, 0}, "square", 4}; // Assuming side length = 4

    std::stringstream out;
    s.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "****\n"
                 "****\n"
                 "****\n"
                 "****\n");
}

TEST(SquareTests, Clone) {
    Square s{{3, 2}, "square", 6}; // Assuming side length = 6

    Square* clone = s.clone();
    delete clone;
}

TEST(SquareTests, Print) {
    Square s{{3, 2}, "square", 6}; // Assuming side length = 6

    std::stringstream out;
    s.print(out);

    EXPECT_STREQ(out.str().c_str(), "square(3, 2)\n");
}

// Triangle Tests
TEST(TriangleTests, Area) {
    EXPECT_EQ(Triangle({0, 0}, "triangle", 5, 4).area(), 10); // Assuming base = 5 and height = 4
}

TEST(TriangleTests, Draw) {
    Triangle t{{0, 0}, "triangle", 4, 3}; // Assuming base = 4 and height = 3

    std::stringstream out;
    t.draw(out);

    EXPECT_STREQ(out.str().c_str(),
                 "  *\n"
                 " ***\n"
                 "****\n");
}

TEST(TriangleTests, Clone) {
    Triangle t{{3, 2}, "triangle", 6, 5}; // Assuming base = 6 and height = 5

    Triangle* clone = t.clone();
    delete clone;
}

TEST(TriangleTests, Print) {
    Triangle t{{3, 2}, "triangle", 6, 5}; // Assuming base = 6 and height = 5

    std::stringstream out;
    t.print(out);

    EXPECT_STREQ(out.str().c_str(), "triangle(3, 2)\n");
}
