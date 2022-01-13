#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    for (int i = 0; i < argc; ++i) {
        cout << argv[i] << endl;
    }

    if (argc > 1) {
        cout << "You want to edit: " << argv[1] << endl;
    } else {
        cout << "You need to add a filename." << endl;
    }

    return 0;
}