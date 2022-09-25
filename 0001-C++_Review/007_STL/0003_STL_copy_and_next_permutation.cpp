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

int main(int argc, char const *argv[])
{
    int  int_a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    permutations(int_a, 1, 4);
    return 0;
}