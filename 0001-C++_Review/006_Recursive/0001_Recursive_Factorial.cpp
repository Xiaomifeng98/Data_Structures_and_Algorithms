#include <iostream>

using namespace std;

int factorial(int n) {
    return (n == 1) ? 1 : (n * factorial(n - 1));
}

int main(int argc, char const *argv[]) {
    cout << factorial(4) << endl;
    return 0;
}