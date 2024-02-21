

#include "picture.hpp"

Picture::Picture() : head(nullptr), tail(nullptr) {}

Picture::Picture(const Picture& other) : Picture() {
    ListNode* current = other.head;
    while (current != nullptr) {
        add(*(current->shape)->clone()); // Clone the shape and add it to the new Picture
        current = current->next;
    }
}

Picture::Picture(Picture&& other) : Picture() {
    swap(other);
}

void Picture::swap(Picture& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
}

Picture& Picture::operator=(const Picture& other) {
    Picture temp(other); // Use copy constructor to create a temporary Picture
    swap(temp); // Swap content with the temporary Picture
    return *this;
}

Picture& Picture::operator=(Picture&& other) {
    swap(other); // Swap content with the other Picture
    return *this;
}

void Picture::add(const Shape& shape) {
    ListNode* newNode = new ListNode{ shape.clone(), nullptr };
    if (!head) { // If list is empty, set head and tail to newNode
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode; // Append newNode to the end
        tail = newNode;
    }
}

void Picture::print_all(std::ostream& out) const {
    ListNode* current = head;
    while (current) {
        current->shape->print(out);
        current = current->next;
    }
}

void Picture::draw_all(std::ostream& out) const {
    ListNode* current = head;
    while (current) {
        current->shape->draw(out);
        current = current->next;
    }
}

double Picture::total_area() const {
    double total = 0.0;
    ListNode* current = head;
    while (current) {
        total += current->shape->area();
        current = current->next;
    }
    return total;
}

Picture::~Picture() {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current->shape; // Delete the shape
        delete current; // Delete the node
        current = next;
    }
}
