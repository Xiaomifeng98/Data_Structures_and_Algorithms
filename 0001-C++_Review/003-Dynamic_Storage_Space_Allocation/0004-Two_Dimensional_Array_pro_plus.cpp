/**
 * 1. 列数未知
 * 2. 函数中不处理异常
 * 3. 调用者捕获异常
 */
 #include <iostream>

using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, int numberOfColumns) {
	// 创建行指针
	x = new T * [numberOfRows];

	// 为每一行分配空间
	for (int i = 0; i < numberOfRows; i++)
	{
		x[i] = new int [numberOfColumns];
	}
}

int main(int argc, char const *argv[])
{
	int **a;
	try {
		make2dArray(a, 3, 5);
		cout << "Successfully created array." << endl;
	} catch (bad_alloc) {
		cerr << "Failed to create array." << endl;
		exit(1);
	}
	return 0;
}