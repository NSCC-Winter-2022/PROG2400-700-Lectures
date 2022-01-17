#include <iostream>

using namespace std;

int main() {

    char command;
    int start, end;

    cout << "Enter a command and two numbers: ";
    cin >> command >> start >> end;

    cout << "command: " << command;
    cout << ", start: " << start;
    cout << ", end: " << end << endl;

    return 0;
}