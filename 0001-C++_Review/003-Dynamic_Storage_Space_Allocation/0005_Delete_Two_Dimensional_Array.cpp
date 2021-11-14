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
    } catch(bad_alloc) {
        return false;
    }
}

template <class T>
void delete2dArray(T ** &x, int numberOfRows) {
	for (int i = 0; i < numberOfRows; i++) {
		delete [] x[i];
	}

	delete [] x;
	x = NULL;	// 防止用户继续访问已被释放的空间
}

int main(int argc, char const *argv[])
{
    int **a;
    if (make2dArray(a, 3, 5))
    {
        cout << "Successfully created array." << endl;
    } else {
        cout << "Failed to create array." << endl;
        exit(1);
    }
    delete2dArray(a, 3);
    return 0;
}