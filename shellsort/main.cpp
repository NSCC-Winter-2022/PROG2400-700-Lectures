#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void shell_sort(int* array, int len) {

    for (int gap = len / 2; gap > 0; gap /= 2) {

        for (int start = 0; start < gap; start++) {

            // insertion sort
            for (int i = start + gap; i < len; i += gap) {
                // take the current value
                int temp = array[i];

                // shuffle values greater than ahead of this value
                int j;
                for (j = i; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                // put the current value back
                array[j] = temp;
            }
        }
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    shell_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}