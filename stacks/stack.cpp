#include "stack.h"

Stack::~Stack() {
    while (peek() != Grade(-1, -1)) {
        pop();
    }
}

void Stack::push(Grade grade) {

    auto new_node = new Node();
    new_node->m_data = grade;

    // is this the first node?
    if (m_first == nullptr) {
        // yep!
        m_first = new_node;
    } else {
        // nope, one already exists
        new_node->m_next = m_first;
        m_first = new_node;
    }
}

Grade Stack::peek() {
    if (m_first != nullptr) {
        return m_first->m_data;
    }
    return {-1, -1};
}

void Stack::pop() {

    // is the stack empty?
    if (m_first != nullptr) {
        auto node = m_first;

        // detach node
        m_first = node->m_next;

        delete node;
    }
}

std::ostream& operator<<(std::ostream& output, Stack& stack) {

    auto node = stack.m_first;
    while (node != nullptr) {
        output << node->m_data << std::endl;
        node = node->m_next;
    }
    return output;
}
