#include <iostream>

using namespace std;

int main() {
	float *x;
	try {
		x = new float[10000000000];
	} catch (bad_alloc e){
		cerr << "Out of memory" << endl;
		exit(1);
	}
	delete x;
	// Or
	// delete []x;
	return 0;
}