/*
 * 本代码由0001-Template_Function.cpp更改;
 * 在函数adb()执行期间,传入的参数带入了名字a, b, c;
 * 当函数被调用时, 这个程序没有复制实参的值; 函数返回时也没有调用析构函数;
 */

#include <iostream>

using namespace std;


// 更改这个值看看引用参数和传值参数他们的地址有什么不同
#define ENABLE_REFERENCE_PARAMETER 1

template <class T>
#if ENABLE_REFERENCE_PARAMETER
T abc(T& a, T& b, T& c){
#else
T abc(T a, T b, T c){
#endif
	a = a * a;	//如果引用的是地址, 所以这个操作会改变调用此函数传入的第一个值
	cout << "1: 传入之后第一个参数的地址: " << &a << ", 值: " << a << endl;
	return a + b + c;
}

int main(){
	
	//利用模板函数计算三个整数的和
	int x = 2, y = 4, z = 9;
	cout << "0: 传入之前第一个参数的地址: " << &x << ", 值: " << x << endl;
	abc(x, y, z);	// 调用模板函数
	cout << "2: 返回之后第一个参数的地址: " << &x << ", 值: " << x << endl;


	//利用模板函数计算三个浮点数的和
	float i = 4.32, j = 9.76, k = 33.9;
	cout << "0: 传入之前第一个参数的地址: " << &i << ", 值: " << i << endl;
	abc(i, j, k);	// 调用模板函数
	cout << "2: 返回之后第一个参数的地址: " << &i << ", 值: " << i << endl;

	return 0;
}