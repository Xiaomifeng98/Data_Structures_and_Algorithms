 /**
  * 对操作符进行重载
  * 1. +  进行类内重载
  * 2. << 进行类外重载
  * 注意看实现方式有什么不同
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

    currency operator+(const currency&) const;
    currency operator+=(const currency& x)
    {
        amount += x.amount;
        return *this;
    }

    void output(ostream&) const;
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

currency currency::operator+(const currency& x) const
{
    currency result;
    result.amount = amount + x.amount;
    return result;
}

void currency::output(ostream& out) const
{
    long theAmount = amount;
    if (theAmount < 0)
    {
        out << "-";
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    out << "$" << dollars << ".";
    int cents = theAmount - dollars * 100;
    if (cents < 10)
    {
        out << "0";
    }
    out << cents;
}

// 类外重载无法直接x.amount, x.output()辅助输出
ostream& operator<<(ostream& out, const currency& x)
{
    x.output(out);
    return out;
}

int main(int argc, char const *argv[])
{
    currency g, h(PLUS, 3, 50), i, j;

    // 使用两种形式的setValue来赋值
    g.setValue(MINUS, 2, 25);
    i.setValue(-6.45);

    // 相加和output
    j = h + g;
    cout << h << " + " << g << " = " << j << endl;

    // 连续相加两次
    j = i + g + h;
    cout << i << " + " << g << " + " << h << " = " << j << endl;

    // += 和 +
    cout << "Increment " << i << " by " << g
         << " and then add " << h << endl;
    j = (i += g) + h;
    cout << "The result is " << j << endl;
    cout << "Incremented object is " << i << endl;

    // 测试异常
    cout << "\n-----EXCEPTION TEST-------\n"
         << "Attempting to initialize with cents = 152" << endl;
    try {
        i.setValue(PLUS, 3, 152);
    } catch (const char* e) {
        cout << "Caught thrown exception: " << e << endl;
    }

    return 0;
}