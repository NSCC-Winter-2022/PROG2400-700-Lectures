#include <iostream>

using namespace std;

class LinkedListNode {
public:
    int m_data;             // the data to store (could be anything)
    LinkedListNode* m_next; // a pointer to the next node in the chain

    LinkedListNode() : m_data(-1), m_next(nullptr) {}
};

class LinkedList {
private:
    LinkedListNode* m_start;    // points to the first node in the chain

public:
    LinkedList() : m_start(nullptr) {}
    virtual ~LinkedList() {
        LinkedListNode* node = m_start;

        while (node != nullptr) {
            LinkedListNode* temp = node;
            node = node->m_next;
            delete temp;
        }
    }

    void add(int data) {

        // create a new node
        LinkedListNode* new_node = new LinkedListNode();
        new_node->m_data = data;

        // is this the first node in the chain?
        if (m_start == nullptr) {
            // add the first node to the chain
            m_start = new_node;
        } else {
            // adding nodes to the end of an existing chain
            LinkedListNode* node = m_start;
            LinkedListNode* prev = nullptr;

            // look for the node with a null "next" pointer
            while (node != nullptr) {
                prev = node;
                node = node->m_next;
            }

            // attach new node to the end of the chain
            if (prev != nullptr) {
                prev->m_next = new_node;
            }
        }
    }

    void delete_node(int data) {

        LinkedListNode* node = m_start;
        LinkedListNode* prev = nullptr;

        // find the node to delete
        while (node != nullptr) {

            // logic to find the node
            if (node->m_data == data) {
                break;
            }

            prev = node;
            node = node->m_next;
        }

        // did I find the node to delete?
        if (node != nullptr) {

            // am I deleting the first node? or a different node?
            if (prev == nullptr) {
                // we're deleting the first node
                m_start = node->m_next;
            } else {
                // must be a different node!
                prev->m_next = node->m_next;
            }

            delete node;
        }

    }

    friend ostream& operator<<(ostream& output, LinkedList& list);
};

ostream& operator<<(ostream& output, LinkedList& list) {

    LinkedListNode* node = list.m_start;

    // output the data from all the nodes in the chain
    while (node != nullptr) {
        cout << node->m_data << " ";
        node = node->m_next;
    }

    return output;
}

int main() {

    LinkedList list;

    // test 1 - add new nodes
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Test 1" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 2 - deleting node in the middle
    list.delete_node(3); // delete the node with the value of 3

    cout << "Test 2" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 3 - deleting node at the end
    list.delete_node(5); // delete the node with the value of 5

    cout << "Test 3" << endl;
    cout << "------" << endl;
    cout << list << endl;

    // test 4 - deleting node at the beginning
    list.delete_node(1); // delete the node with the value of 1

    cout << "Test 4" << endl;
    cout << "------" << endl;
    cout << list << endl;

    return 0;

}