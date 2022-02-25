#include <iomanip>
#include <iostream>

using namespace std;

class Node;

typedef Node* NodePtr;

class Node {
public:
    int m_data {-1};
    NodePtr m_left {nullptr};
    NodePtr m_right {nullptr};
};

class BST {
private:
    NodePtr m_root {nullptr};

public:
    void Insert(int num) {
        // entry point
        Insert(num, m_root);
    }

protected:
    void Insert(int num, NodePtr& node) {
        if (node == nullptr) {
            node = new Node();
            node->m_data = num;
        } else if (num < node->m_data) {
            // go left!
            Insert(num, node->m_left);
        } else if (num > node->m_data) {
            // go right!
            Insert(num, node->m_right);
        } else {
            // trying to insert node of duplicate value
            cout << "Node value " << node->m_data << " already exists." << endl;
        }
    }

    void PrintTree(ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            PrintTree(output, node->m_right, indent + 8);
            output << setw(indent) << node->m_data << endl;
            PrintTree(output, node->m_left, indent + 8);
        }
    }

    friend ostream& operator<<(ostream& output, BST& bst);
};

ostream& operator<<(ostream& output, BST& bst) {
    bst.PrintTree(output, bst.m_root, 0);
    return output;
}

int main() {

    BST bst;

    // test 1 - inserting nodes
    cout << "Test 1 - adding nodes" << endl;
    cout << "---------------------" << endl;

    bst.Insert(5);
    bst.Insert(3);
    bst.Insert(7);
    bst.Insert(2);
    bst.Insert(4);
    bst.Insert(6);
    bst.Insert(8);

    cout << bst << endl;

    return 0;
}