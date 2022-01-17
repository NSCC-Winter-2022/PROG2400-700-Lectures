#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

ostream& operator<<(ostream& output, vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    return output;
}

int main() {

    vector<int> nums {1, 2, 3, 4, 5};
    //nums.reserve(1000);
    cout << setw(11) << "initial) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // add another number
    cout << setw(11) << "push_back) ";
    nums.push_back(6);
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // remove a couple of numbers
    cout << setw(11) << "resize) ";
    nums.resize(4);
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // get rid of all numbers
    cout << setw(11) << "clear) ";
    nums.clear();
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // get rid of all memory allocated
    cout << setw(11) << "shrink) ";
    nums.shrink_to_fit();
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    return 0;
}