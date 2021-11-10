#include <iostream>

using namespace std;

template <class T>
T abc(T a, T b, T c){
	if (c == 0) {
		throw "----------------------------------------\nERROR: The first parameter is equal to 0\n----------------------------------------";
	} else if (c < 0)
	{
		throw 2;
	}
	return (a + b) / c;
}

int main() {

	int x = 5, y = 4, z = -10;
	try { // 捕捉到异常后不会在try中继续往下执行, 直接跳转到catch中
		cout << abc(x, y, z) << endl;
		cout << abc(5, 5, 5) << endl;
	} catch (char const* e){ // 上面第一个抛出的异常类型为char const*, 所以此处不能填写char*
		cout << e << endl;
	} catch (int num){ // 上面第二个抛出异常的类型为int
		cout << "I have caught an exception of int type: " << num << endl;
	}

	cout << abc(1.2, 5.5, 65.4) << endl;

	return 0;
}