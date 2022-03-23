#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

int split(int* array, int first, int last) {

    // pick a pivot point
    int pivot = array[first];

    // start searching for numbers less than and greater than the pivot
    int left = first;
    int right = last;

    // keep searching until all elements are in their correct spots
    while (left < right) {

        // move all less than the pivot to the left
        while (pivot < array[right]) {
            right--;
        }

        // move all greater than the pivot to the right
        while (pivot >= array[left]) {
            left++;
        }

        // if two were found out of place, swap them
        if (left < right) {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            // swap(array[left], array[right]);
        }
    }

    // now move the pivot between the two sublists
    array[first] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(int* array, int first, int last) {

    // how to determine it is sorted?
    // when sorting an array of one element, first == last
    // when sorting an array of no elements, first > last

    if (first < last) {
        // split into sublists
        // "pos" is the position of the "pivot point"
        int pos = split(array, first, last);

        // sort the left sublist
        quick_sort(array, first, pos - 1);

        // sort the right sublist
        quick_sort(array, pos + 1, last);
    }
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    quick_sort(nums, 0, len - 1);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}