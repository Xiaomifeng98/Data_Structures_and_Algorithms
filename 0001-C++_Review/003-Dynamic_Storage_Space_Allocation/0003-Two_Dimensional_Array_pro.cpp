/**
 * 1. 列数未知
 * 2. 若分配空间异常, 在函数中抛出异常
 * 3. 通过返回值告知是否创建成功
 */
#include <iostream>

using namespace std;

template <class T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns) {
	try {
		// 创建行指针
		x = new T * [numberOfRows];

		// 为每一行分配空间
		for (int i = 0; i < numberOfRows; i++)
		{
			x[i] = new int [numberOfColumns];
		}
		return true;
	} catch(bad_alloc) {	// 当地址不够了才会出现这个异常
		return false;
	}
}

int main(int argc, char const *argv[])
{
	int **a;
	if (make2dArray(a, 3, 5))
	{
		cout << "Successfully created array." << endl;
	} else {
		cout << "Failed to create array." << endl;
	}
	return 0;
}