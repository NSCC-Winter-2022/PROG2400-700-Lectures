#include <iostream>
#include <memory>

using namespace std;

class Node {
public:
    int m_data {-1};
    Node* m_next {nullptr};
};

class Queue {
private:
    Node* m_first {nullptr};
    Node* m_last {nullptr};

public:
    Queue() = default;
    virtual ~Queue() {
        while (m_first != nullptr) {
            pop();
        }
    }

    void push(int num) {

        Node* new_node = new Node();
        new_node->m_data = num;

        // are we adding the first node?
        if (m_first == nullptr) {
            // first node
            m_first = new_node;
        } else {
            // last node
            m_last->m_next = new_node;
        }

        // last always points to the new node
        m_last = new_node;
    }

    int peek() {
        // are there any nodes to see?
        if (m_first == nullptr)
            return -1; // return -1 if no nodes exist
        else
            return m_first->m_data;
    }

    int pop() {

        Node* node = m_first;
        // std::unique_ptr<Node> node = static_cast<std::unique_ptr<Node>>(m_first);

        // detach previous first node
        m_first = m_first->m_next;

        int num = node->m_data;

        delete node;

        return num;
    }

    friend ostream& operator<<(ostream& output, Queue& queue);
};

ostream& operator<<(ostream& output, Queue& queue) {

    Node* node = queue.m_first;

    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Queue queue;

    // test 1: add nodes to queue
    cout << "Test 1: Pushing Nodes" << endl;
    cout << "---------------------" << endl;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    cout << queue << endl;

    // test 2: look at value of first node
    cout << "Test 2: Peek at the first node" << endl;
    cout << "------------------------------" << endl;

    cout << queue.peek() << endl;

    // test 3: remove the node and look at the value
    cout << "Test 3: Pop off the first node" << endl;
    cout << "------------------------------" << endl;

    auto num = queue.pop();
    cout << num << endl;
    cout << queue << endl;

    return 0;
}