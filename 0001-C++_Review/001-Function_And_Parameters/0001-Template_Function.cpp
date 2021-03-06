#include <iostream>

using namespace std;

// 转到文件./0003...cpp看看传值参数和引用参数地址有什么不同
template <class T>
T abc(T a, T b, T c){
	return a + b + c;
}

int main(){
	
	//利用模板函数计算三个整数的和
	int x = 2, y = 4, z = 9;
	cout << abc(x, y, z) << endl;

	//利用模板函数计算三个浮点数的和
	float i = 4.32, j = 9.76, k = 33.9;
	cout << abc(i, j, k) << endl;

	return 0;
}