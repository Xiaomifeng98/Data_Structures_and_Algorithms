#include <iostream>

using namespace std;

template<class T>
T sum(T a[], int n) {
        return  n > 0 ? sum(a, n - 1) + a[n - 1] : 0;
}

template<class T>
T sum_recursive(T a[], int n) {
    T theSum = 0;
    for (int i = 0; i < n; i++)
        theSum += a[i];
    return theSum;
}

int main(int argc, char const *argv[]) {
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << sum(a, 7) << endl;              // 不使用递归
    cout << sum_recursive(a, 7) << endl;    // 使用递归

    return 0;
}