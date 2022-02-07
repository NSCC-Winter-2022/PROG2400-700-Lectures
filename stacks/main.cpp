#include "grade.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main() {

    Stack stack;

    // test 1 - adding first node to the stack
    cout << "Test 1: add first node" << endl;
    cout << "----------------------" << endl;

    stack.push({10, 20});

    cout << stack << endl;

    // test 2 - adding more nodes to the stack
    cout << "Test 2: add more nodes" << endl;
    cout << "----------------------" << endl;

    stack.push({20, 25});
    stack.push({25, 35});
    stack.push({35, 45});
    stack.push({45, 55});

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

    while (stack.peek() != Grade(-1, -1)) {
        stack.pop();
    }

    cout << stack << endl;

    // test 6 - adding a first node to the stack again
    cout << "Test 6: add first node again" << endl;
    cout << "----------------------------" << endl;

    stack.push({60, 70});

    cout << stack << endl;

    return 0;
}