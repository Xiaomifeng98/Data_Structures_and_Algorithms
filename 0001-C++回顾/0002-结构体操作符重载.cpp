#include <iostream>

using namespace std;

struct Student{
	string name;
	float core;

	// 结构体运算符 + 重载
	float operator + (const Student st)const{
		return core + st.core;
	}

	// 结构体操作符 << 重载------Type1
	friend ostream& operator << (ostream &out, Student st){
		out<< "name: " << st.name << ", \t core: " << st.core << endl;
		return out;
	}

	// 结构体操作符 << 重载------Type2---不推荐
	ostream& operator << (ostream &out)const{
		out<< "name: " << name << ", \t core: " << core << endl;
		return out;
	}

	// 结构体操作符 < 重载
	bool operator < (const Student st)const{
		return core < st.core;
	}

};

int main(){
	Student A{
		.name = "Jack",
		.core = 78.4,
	};

	Student B{
		.name = "Pink",
		.core = 65.7,
	};

	Student C{
		.name = "Link",
		.core = 86.1,
	};

	cout << A + B << endl;			// 加号运算符重载

	cout << A << B << C << endl;	// 输出操作符重载---Type1

	A << cout << B << C << endl;	// 输出操作符重载---Type2---不推荐

	cout << ( A < C ) << endl;		// < 操作符重载

	return 0;
}