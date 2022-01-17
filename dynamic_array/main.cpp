#include <iostream>
#include <iomanip>

using namespace std;

class DynamicArray {
private:
    int *m_nums;
    int m_size;
    int m_capacity;

public:
    DynamicArray() : m_nums(nullptr), m_size(0), m_capacity(0) {}
    virtual ~DynamicArray() {
        delete [] m_nums;
    }

    int capacity() { return m_capacity; }

    void add(int num) {
        // re-allocate memory for new element
        int *temp = m_nums;
        m_capacity += 5;
        m_nums = new int[m_capacity];

        // copy old elements to new array
        int i;
        for (i = 0; i < m_size; ++i) {
            m_nums[i] = temp[i];
        }

        // add new element
        m_nums[i] = num;
        m_size++;

        delete [] temp;
    }

    void resize(int size) {
        m_size = size;
    }

    friend ostream& operator<<(ostream& output, DynamicArray& array);
};

ostream& operator<<(ostream& output, DynamicArray& array) {
    for (int i = 0; i < array.m_size; ++i) {
        cout << array.m_nums[i] << ' ';
    }
    return output;
}

int main() {

    // test 1 - create an array
    DynamicArray nums;
    nums.add(1);
    nums.add(2);
    nums.add(3);
    nums.add(4);
    nums.add(5);
    cout << setw(11) << "initial) ";
    cout << setw(2) << "capacity: " << nums.capacity() << ") ";
    cout << nums << endl;

    // test 2 - add another element
    nums.add(6);
    cout << setw(11) << "add) ";
    cout << setw(2) << "capacity: " << nums.capacity() << ") ";
    cout << nums << endl;

    // test 3 - resize the array
    nums.resize(4);
    cout << setw(11) << "resize) ";
    cout << setw(2) << "capacity: " << nums.capacity() << ") ";
    cout << nums << endl;

    return 0;
}