/**
 * 接着0003的程序继续往下写一个sort的函数
 */

#include <iostream>
#include <numeric>  // accumulate(...)函数的头文件
#include <algorithm>
#include <iterator>

using namespace std;

template<class T>
void permutations(T list[], int k, int m) {
    do {
        copy(list + k, list + m, ostream_iterator<T>(cout, ""));
        cout << endl;
    } while (next_permutation(list + k, list + m));
}

template<class T>
void sort_and_permutations(T list[], int k, int m) {
    sort(list + k, list + m);
    permutations(list, k, m);
}

int main(int argc, char const *argv[])
{
    int  int_a[10] = {1, 4, 2, 3, 5, 6, 7, 8, 9, 10};
    // permutations(int_a, 1, 4);
    // sort(int_a, int_a + 4);  // 展示sort(start, end)的用法: 按照升序排列int_a[k:m-1]
    sort_and_permutations(int_a, 1, 4);  // 按照升序排列, 并输出下一个更大的排列
    return 0;
}