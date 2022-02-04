#ifndef _STACK_H
#define _STACK_H

#include <iostream>

#include "grade.h"

class Node {
public:
    Grade m_data;
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_first {nullptr};

public:
    Stack() = default;
    virtual ~Stack();

    void push(Grade num);
    Grade peek();
    void pop();

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif