#include <iostream>

using namespace std;

// 5! = 5 * 4 * 3 * 2 * 1

int calc_factorial(int factorial) {

    if (factorial == 1)
        return 1;

    return factorial * calc_factorial(factorial - 1);
}

int main() {

    int factorial;

    cout << "Enter a number: ";
    cin >> factorial;

    int answer = 1;
    for (int i = factorial; i >= 1; --i) {
        answer *= i;
    }

    cout << factorial << "! = " << answer << endl;

    cout << factorial << "! = " << calc_factorial(factorial) << endl;

    return 0;
}