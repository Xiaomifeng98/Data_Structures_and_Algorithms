// Known number of columns
#include <iostream>

using namespace std;

int main() {
	int n = 10;
	// *c[0], *c[1], *c[2], *c[3], *c[4]
	// *c 又可以是一维数组
	// 如此 (*c) [5] 就是列数为5的二维数组
	char (*c) [5];
	try {
		c = new char[n][5];
	} catch (bad_alloc e){
		cerr << "Out of memory" << endl;
		exit(1);
	}
	delete c;
	return 0;
}