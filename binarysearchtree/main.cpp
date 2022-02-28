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
    void insert(int num) {
        // entry point
        insert(num, m_root);
    }

    void remove(int num) {

        NodePtr node = m_root;
        NodePtr parent = nullptr;

        // find node to delete
        while (node != nullptr) {
            if (num < node->m_data) {
                // go to the left
                parent = node;
                node = node->m_left;
            } else if (num > node->m_data) {
                // go to the right
                parent = node;
                node = node->m_right;
            } else {
                // found the node!
                break;
            }
        }

        // exit if node was not found
        if (node == nullptr)
            return;

        // find a successor, if the node has two children
        if (node->m_left != nullptr && node->m_right != nullptr) {
            // start at the left subtree
            NodePtr successor = node->m_left;

            // now go right as far as possible
            parent = node;
            while (successor->m_right != nullptr) {
                parent = successor;
                successor = successor->m_right;
            }

            // swap values with the successor
            node->m_data = successor->m_data;
            node = successor;
        }

        // do we have any children?
        NodePtr subtree = node->m_left;
        if (subtree == nullptr) {
            subtree = node->m_right;
        }

        // which side are we connected to?
        if (parent == nullptr) {
            m_root = subtree;
        } else if (node == parent->m_left) {
            parent->m_left = subtree;
        } else if (node == parent->m_right) {
            parent->m_right = subtree;
        }

        // finally!
        delete node;
    }

protected:
    void insert(int num, NodePtr& node) {
        if (node == nullptr) {
            node = new Node();
            node->m_data = num;
        } else if (num < node->m_data) {
            // go left!
            insert(num, node->m_left);
        } else if (num > node->m_data) {
            // go right!
            insert(num, node->m_right);
        } else {
            // trying to insert node of duplicate value
            cout << "Node value " << node->m_data << " already exists." << endl;
        }
    }

    void print_tree(ostream& output, NodePtr& node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->m_right, indent + 8);
            output << setw(indent) << node->m_data << endl;
            print_tree(output, node->m_left, indent + 8);
        }
    }

    friend ostream& operator<<(ostream& output, BST& bst);
};

ostream& operator<<(ostream& output, BST& bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}

int main() {

    BST bst;

    // test 1 - inserting nodes
    cout << "Test 1 - adding nodes" << endl;
    cout << "---------------------" << endl;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << bst << endl;

    // test 2 - deleting nodes
    cout << "Test 2 - removing nodes" << endl;
    cout << "-----------------------" << endl;

    bst.remove(2);

    cout << bst << endl;

    cout << "---" << endl;

    bst.remove(3);

    cout << bst << endl;

    cout << "---" << endl;

    bst.remove(7);

    cout << bst << endl;

    cout << "---" << endl;

    bst.remove(5);

    cout << bst << endl;

    cout << "---" << endl;

    bst.remove(4);

    cout << bst << endl;

    return 0;
}