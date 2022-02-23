#include <cstring>
#include <iostream>

using namespace std;

bool is_palindrome(char* input, int len) {

    for (int i = 0; i < len / 2; ++i) {
        if (input[i] != input[len - i - 1]) {
            return false;
        }
    }
    return true;
}

bool is_palindrome_recursive(char* input, int len) {

    // racecar -> compare the 'r' and the rest
    if (len <= 1)
        return true;

    char first = input[0];
    char last = input[len - 1];

    if (first == last) {
        // check the rest if it is a palindrome
        char* substr = new char[len - 1];
        strncpy(substr, &input[1], len - 2);
        substr[len - 2] = '\0';

        bool retval = is_palindrome_recursive(substr, len - 2);

        delete[] substr;

        return retval;
    }

    return false;
}

int main() {

    constexpr int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];

    cout << "Enter a word: ";
    cin.getline(buffer, BUFFER_SIZE);

    if (is_palindrome(buffer, strlen(buffer))) {
        cout << buffer << " IS a palindrome!" << endl;
    } else {
        cout << buffer << " IS NOT a palindrome!" << endl;
    }

    if (is_palindrome_recursive(buffer, strlen(buffer))) {
        cout << buffer << " IS a palindrome!" << endl;
    } else {
        cout << buffer << " IS NOT a palindrome!" << endl;
    }

    return 0;
}