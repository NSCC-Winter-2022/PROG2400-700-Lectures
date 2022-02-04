#include <iostream>

using namespace std;

class Node {
public:
    int m_data {-1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_first {nullptr};

public:
    Stack() = default;
    virtual ~Stack() {
    }

    void push(int num) {

        auto new_node = new Node();
        new_node->m_data = num;

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

    int peek() {
        if (m_first != nullptr) {
            return m_first->m_data;
        }
        return -1;
    }

    void pop() {

        // is the stack empty?
        if (m_first != nullptr) {
            auto node = m_first;

            // detach node
            m_first = node->m_next;

            delete node;
        }
    }

    friend ostream& operator<<(ostream& output, Stack& stack);
};

ostream& operator<<(ostream& output, Stack& stack) {

    auto node = stack.m_first;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Stack stack;

    // test 1 - adding first node to the stack
    cout << "Test 1: add first node" << endl;
    cout << "----------------------" << endl;

    stack.push(1);

    cout << stack << endl;

    // test 2 - adding more nodes to the stack
    cout << "Test 2: add more nodes" << endl;
    cout << "----------------------" << endl;

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << stack << endl;

    // test 3 - read first node from the stack
    cout << "Test 3: get data from first node" << endl;
    cout << "--------------------------------" << endl;

    cout << stack.peek() << endl;

    // test 4 - remove first node from the stack
    cout << "Test 4: pop first node off stack" << endl;
    cout << "--------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    // test 5 - remove remaining nodes from the stack
    cout << "Test 5: pop other nodes off stack" << endl;
    cout << "---------------------------------" << endl;

    while (stack.peek() != -1) {
        stack.pop();
    }

    cout << stack << endl;

    // test 6 - adding a first node to the stack again
    cout << "Test 6: add first node again" << endl;
    cout << "----------------------------" << endl;

    stack.push(6);

    cout << stack << endl;

    return 0;
}