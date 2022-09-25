#include <iostream>
#include <numeric>  // accumulate(...)函数的头文件

using namespace std;

template<class T>
T sum(T a[], int n, T initialValue = 0) {
    return accumulate(a, a+n, initialValue);    // 返回数组a[0：n-1]的累积和 + initialValue
}

int main(int argc, char const *argv[])
{
    char char_a[10] = {'a', 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(char_a, 4) << endl;
    int  int_a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(int_a, 4, 5) << endl;
    return 0;
}