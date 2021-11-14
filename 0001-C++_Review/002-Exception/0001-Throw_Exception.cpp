#include <iostream>

using namespace std;

template <class T>
T abc(T a, T b, T c){
	if (c <= 0) {
		throw "The first parameter is less than or equal to 0";
	}
	return (a + b) / c;
}

int main() {

	int x = 5, y = 4, z = 0;

	// 这个程序只是让它抛出了异常, 并没有做处理
	cout << abc(x, y, z) << endl;

	return 0;
}