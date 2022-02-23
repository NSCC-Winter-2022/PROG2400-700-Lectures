#include <iostream>

using namespace std;

int count = 0;

void recursive_function() {
    cout << "Hello World" << endl;

    count++;
    if (count < 10000000) {
        recursive_function();
    }
}

int main() {
    recursive_function();
    return 0;
}