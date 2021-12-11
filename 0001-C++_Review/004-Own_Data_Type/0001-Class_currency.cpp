 /**
  * 假定处理货币类型currency的对象.
  * 这个对象有三个成员: 符号(+或-), 美元, 美分.
  * 例如: $2.35(2美元, 35美分, 符号是+), -$6.05(6美元, 5美分, 符号是-).
  * 对这种对象执行以下操作:
  *   1. 给成员赋值
  *   2. 确定成员值(即符号, 美元数目和美分数目)
  *   3. 两个对象相加
  *   4. 增加成员的值
  *   5. 输出
  */

#include <iostream>

using namespace std;

enum signType { PLUS, MINUS };

class currency
{
public:
    // 构造函数
    currency(signType theSign = PLUS,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);

    // 析构函数
    ~currency();

    // 设置值
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);

    // 获取值
    signType getSign() const {return sign;}
    unsigned long getDollars() const {return dollars;}
    unsigned int getCents() const {return cents;}

    // 相加
    currency add(const currency&) const;
    currency& increment(const currency&);

    void output() const;
private:
    signType sign;                // 对象的符号
    unsigned long dollars;        // 美元的数量
    unsigned int cents;           // 美分的数量

};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

currency::~currency(){

}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    if (theCents > 99)
    {
        throw "Cents should be < 100";
    }

    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}

void currency::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        sign = MINUS;
        theAmount = -theAmount;
    } else {
        sign = PLUS;
    }

    dollars = (unsigned long) theAmount;
    // 为什么＋0.001, 详见书 [ P15-程序 1-15 ]上面文字说明
    cents = (unsigned int)((theAmount + 0.001 - dollars) * 100);
}

currency currency::add(const currency& x) const
{
    long a1, a2, a3;
    currency result;

    a1 = dollars * 100 + cents;
    if (sign == MINUS)
    {
        a1 = -a1;
    }

    a2 = x.dollars * 100 + x.cents;
    if (x.sign == MINUS)
    {
        a2 = -a2;
    }

    a3 = a1 + a2;

    if (a3 < 0)
    {
        result.sign = MINUS;
        a3 = -a3;
    } else {
        result.sign = PLUS;
    }
    result.dollars = a3/100;
    result.cents = a3 - result.dollars * 100;

    return result;
}

currency& currency::increment(const currency& x)
{
    *this = add(x);
    return *this;
}

void currency::output() const
{
    if (sign == MINUS)
    {
        cout << "-";
    }
    cout << "$" << dollars << ".";
    if (cents < 10)
    {
        cout << "0";
    }
    cout << cents;
}

int main(int argc, char const *argv[])
{
    currency g, h(PLUS, 3, 50), i, j;

    // 使用两种形式的setValue来赋值
    g.setValue(MINUS, 2, 25);
    i.setValue(-6.45);

    // 调用成员函数add和output
    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

    // 连续调用两次成员函数add
    j = i.add(g).add(h);
    j.output(); cout << endl;

    // 调用成员函数increment和add
    j = i.increment(g).add(h);
    j.output(); cout << endl;

    // 测试异常
    cout << "\n----------------\nAttempting to initialize with cents = 152" << endl;
    try {
        i.setValue(PLUS, 3, 152);
    } catch (const char* e) {
        cout << "Caught thrown exception: " << e << endl;
    }

    return 0;
}