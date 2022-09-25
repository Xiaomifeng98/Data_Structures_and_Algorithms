#include <iostream>
#include <numeric>  // accumulate(...)函数的头文件

using namespace std;

template<class T>
T product(T a[], int n, T initialValue = 1) {
    // 返回数组a[0：n-1]的累积乘积 x initialValue
    return accumulate(a, a+n, initialValue, multiplies<T>());
}

int main(int argc, char const *argv[])
{
    int  int_a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << product(int_a, 4) << endl;
    return 0;
}