/*
 * 本代码由0003-Reference_Parameter.cpp更改
 */

#include <iostream>

using namespace std;


// 更改这个值看看引用参数和传值参数他们的地址有什么不同
#define ENABLE_CONST_PARAMETER 1

template <class T>
#if ENABLE_CONST_PARAMETER
T abc(const T& a, const T& b, const T& c){
#else
T abc(T& a, T& b, T& c){
	a = a * a;	//在使用常量引用时, 此处报错, 因为不允许改变被const修饰的值
#endif
	return a + b + c;
}

int main(){
	
	//利用模板函数计算三个整数的和
	int x = 2, y = 4, z = 9;
	cout << abc(x, y, z) << endl;	// 调用模板函数


	//利用模板函数计算三个浮点数的和
	float i = 4.32, j = 9.76, k = 33.9;
	cout << abc(i, j, k) << endl;	// 调用模板函数

	return 0;
}