#include <iostream>

using namespace std;

template <class Ta, class Tb, class Tc>
Tc abc(const Ta& a, const Tb& b, const Tc& c){
	return a + b + c;
}

int main(){
	
	//利用模板函数计算三个不同类型的和
	int x = 2;
	float y = 4.5;
	double z = 2.55584;
	cout << abc(x, y, z) << endl;

	return 0;
}