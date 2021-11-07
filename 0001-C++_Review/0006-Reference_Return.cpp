#include <iostream>

using namespace std;

template <class T>
T& setValue(T& z){
    return z;
}

template <class Ta, class Tb>
Ta& setValue(Ta& a, Tb b){
    a = b;
    return a;
}

template <class T>
const T& setConstValue(T& z){
    z = 'l';    // 可以在返回之前赋值
    return z;
}

int main()
{
    char values[5] = {'a', 'b', 'c', 'd', 'e'};

    cout << "setValue之前数组value: \t\t\t\t\t\t\t\t" << values << endl;
    setValue(values[2]) = 'i';
    setValue(values[3], 'j');
    // setConstValue(values[4]) = 'k'; 错误代码! 返回类型为const T&, 无法在此改变!
    cout << "setValue之后数组value: \t\t\t\t\t\t\t\t" << values << endl << endl;

    setConstValue(values[4]);
    cout << "setConstValue之后数组value: \t\t\t\t\t\t\t" << values << endl;

    values[4] = 'm';
    cout << "setConstValue后面的程序不受setConstValue的const影响: \t" << values << endl;
    return 0;
}