#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void insertion_sort(int* array, int len) {
    for (int i = 1; i < len; i++) {
        // take the current value
        int temp = array[i];

        // shuffle values greater than ahead of this value
        int j;
        for (j = i; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }

        // put the current value back
        array[j] = temp;
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    insertion_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}