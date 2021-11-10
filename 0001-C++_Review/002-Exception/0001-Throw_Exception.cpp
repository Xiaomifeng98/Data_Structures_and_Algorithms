#include <iostream>

using namespace std;

// 转到文件./0003...cpp看看传值参数和引用参数地址有什么不同
template <class T>
T abc(T a, T b, T c){
	if (c <= 0) {
		throw "The first parameter is less than or equal to 0";
	}
	return (a + b) / c;
}

int main() {

	int x = 5, y = 4, z = 0;
	cout << abc(x, y, z) << endl;

	return 0;
}