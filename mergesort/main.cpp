#include <iomanip>
#include <iostream>

using namespace std;

void dump_array(int* array, int len) {
    for (int i = 0; i < len; i++) {
        cout << setw(3) << array[i];
    }
    cout << endl;
}

void split(int* inarray, int len, int* outarray1, int* outsize1, int* outarray2, int* outsize2) {

    // not needed for file version
    int in = 0;
    *outsize1 = 0;
    *outsize2 = 0;

    // the total number of subfiles
    int subfiles = 0;

    // read first record
    int curr;
    int next = inarray[in++];

    // loop until no more records to split
    while (in <= len) {

        // loop until no more records in the current ordered list
        do {
            curr = next;

            // read in next record
            if (in < len) {
                next = inarray[in];
            }
            in++;

            // determine odd/even
            if (subfiles % 2 == 0) {
                // even, write record to first temporary file
                outarray1[(*outsize1)++] = curr;
            } else {
                // odd, write record to second temporary file
                outarray2[(*outsize2)++] = curr;
            }

        } while ((curr < next) && (in <= len));

        subfiles++;
    }
}

int merge(int* outarray, int* outsize, int* inarray1, int insize1, int* inarray2, int insize2) {

    // not needed in the file version
    int in1 = 0;
    int in2 = 0;
    *outsize = 0;

    // the total number of subfiles left after merge
    int subfiles = 0;

    // read one record from each file
    int prev1;
    int prev2;
    int curr1;
    int curr2;

    curr1 = inarray1[in1++];
    curr2 = inarray2[in2++];

    // loop while both files have records
    while (in1 <= insize1 && in2 <= insize2) {

        bool end_of_sub1 = false;
        bool end_of_sub2 = false;

        // loop through one sublist at a time
        while (!end_of_sub1 && !end_of_sub2) {

            // compare records
            if (curr1 <= curr2) {
                // write out appropriate record
                outarray[(*outsize)++] = curr1;

                // read the next one in
                prev1 = curr1;
                if (in1 < insize1) {
                    curr1 = inarray1[in1];
                }
                in1++;

                // did I cross to a different sublist?
                if ((prev1 > curr1) || (in1 > insize1)) {
                    end_of_sub1 = true;
                }
            }

            if (curr2 <= curr1) {
                // write out appropriate record
                outarray[(*outsize)++] = curr2;

                // read the next one in
                prev2 = curr2;
                if (in2 < insize2) {
                    curr2 = inarray2[in2];
                }
                in2++;

                // did I cross to a different sublist?
                if ((prev2 > curr2) || (in2 > insize2)) {
                    end_of_sub2 = true;
                }
            }
        }

        // write out remaining records from the same sublist in the file that still has some
        while (!end_of_sub1) {
            // write out appropriate record
            outarray[(*outsize)++] = curr1;

            // read the next one in
            prev1 = curr1;
            if (in1 < insize1) {
                curr1 = inarray1[in1];
            }
            in1++;

            // did I cross to a different sublist?
            if ((prev1 > curr1) || (in1 > insize1)) {
                end_of_sub1 = true;
            }
        }

        while (!end_of_sub2) {
            // write out appropriate record
            outarray[(*outsize)++] = curr2;

            // read the next one in
            prev2 = curr2;
            if (in2 < insize2) {
                curr2 = inarray2[in2];
            }
            in2++;

            // did I cross to a different sublist?
            if ((prev2 > curr2) || (in2 > insize2)) {
                end_of_sub2 = true;
            }
        }

        subfiles++;
    }

    // write out remaining records from the file that still has some
    while (in1 <= insize1) {
        // write out appropriate record
        outarray[(*outsize)++] = curr1;

        // read the next one in
        prev1 = curr1;
        if (in1 < insize1) {
            curr1 = inarray1[in1];
        }
        in1++;

        // did I cross to a different sublist?
        if ((prev1 > curr1) || (in1 > insize1)) {
            subfiles++;
        }
    }

    while (in2 <= insize2) {
        // write out appropriate record
        outarray[(*outsize)++] = curr2;

        // read the next one in
        prev2 = curr2;
        if (in2 < insize2) {
            curr2 = inarray2[in2];
        }
        in2++;

        // did I cross to a different sublist?
        if ((prev2 > curr2) || (in2 > insize2)) {
            subfiles++;
        }
    }

    return subfiles;
}

void merge_sort(int* array, int len) {

    int subfiles = 0;
    int* temp1 = new int[len];
    int* temp2 = new int[len];
    int tempsize1;
    int tempsize2;

    // loop until completely sorted
    do {
        // split
        split(array, len, temp1, &tempsize1, temp2, &tempsize2);

        // merge
        subfiles = merge(array, &len, temp1, tempsize1, temp2, tempsize2);
    } while (subfiles != 1);

    delete[] temp1;
    delete[] temp2;
}

int main() {

    int nums[] = {3, 6, 8, 10, 5, 9, 4, 7, 1, 2};
    int len = sizeof(nums) / sizeof(int);

    cout << "Before Sorting..." << endl;
    dump_array(nums, len);

    merge_sort(nums, len);

    cout << "After Sorting..." << endl;
    dump_array(nums, len);

    return 0;
}