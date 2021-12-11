 /**
  * 类currency的另一种实现方式
  * 因为用户仅仅通过共有部分所提供的接口与类currency进行交互,
  * 所以对私有部分的修改不会影响程序的正确性
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
    signType getSign() const
    {
        if (amount < 0)
        {
            return MINUS;
        } else {
            return PLUS;
        }
    }
    unsigned long getDollars() const
    {
        if (amount < 0)
        {
            return (-amount) / 100;
        } else {
            return amount / 100;
        }
    }
    unsigned int getCents() const
    {
        if (amount < 0)
        {
            return -amount - getDollars() * 100;
        } else {
            return amount - getDollars() * 100;
        }
    }

    // 相加
    currency add(const currency&) const;
    currency& increment(const currency& x)
    {
        amount += x.amount;
        return *this;
    }

    void output() const;
private:
    long amount;

};

currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}

currency::~currency()
{
    // Nothing to do
}

void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    if (theCents > 99)
    {
        throw "Cents should be < 100";
    }

    amount = theDollars * 100 + theCents;
    if (theSign == MINUS)
    {
        amount = -amount;
    }
}

void currency::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        amount = (long)((theAmount - 0.001) * 100);
    } else {
        amount = (long)((theAmount + 0.001) * 100);
    }
}

currency currency::add(const currency& x) const
{
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency::output() const
{
    long theAmount = amount;
    if (theAmount < 0)
    {
        cout << "-";
        theAmount = -theAmount;
    }

    long dollars = theAmount / 100;
    cout << "$" << dollars << ".";

    int cents = theAmount - dollars * 100;
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