#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void selection_sort(int* array, int len) {
    for (int i = 0; i < len - 1; i++) {

        // find the smallest number
        int lowest = i;
        for (int j = i; j < len; j++) {
            if (array[j] < array[lowest]) {
                lowest = j;
            }
        }

        if (array[lowest] < array[i]) {
            // put the lowest number where it should go
            // int temp = array[lowest];
            // array[lowest] = array[i];
            // array[i] = temp;
            swap(array[lowest], array[i]);
        }
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    selection_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}