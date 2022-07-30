#include <iostream>
#include <iterator>

using namespace std;

static int K = 0;

template<class T>
void swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T>
void permutation(T list[], int k, int m) {
    if (k == m) {
        // 书上的程序在这里没有K, 只能输出0~m的所有排列;
        // 带上了之后就正常了
        copy(list + K, list + m + 1, ostream_iterator<T>(cout, ""));
        cout << endl;
    } else {
        for (int i = k; i <= m; i++)
        {
            ::swap(list[k], list[i]);   // 标准库中也有swap, 所以这里带上::
            permutation(list, k + 1, m);
            ::swap(list[k], list[i]);
        }
    }
}

int main(int argc, char const *argv[]) {
    int a[10] = {0, 1, 2, 3};
    K = 1;
    permutation(a, K, 3);
    return 0;
}