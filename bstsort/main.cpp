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

    void save_array(int* array) {
        save_array(array, m_root);
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

    void save_array(int* array, NodePtr node) {
        // position in the array to store value
        static int i = 0;

        if (node != nullptr) {
            save_array(array, node->m_right);
            array[i++] = node->m_data;
            save_array(array, node->m_left);
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

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void bst_sort(int* array, int len) {

    BST bst;

    for (int i = 0; i < len; i++) {
        bst.insert(array[i]);
    }

    bst.save_array(array);
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    bst_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}