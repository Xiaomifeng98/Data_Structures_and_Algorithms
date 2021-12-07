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

enum signType { plus, minus };

class currency
{
public:
    // 构造函数
    currency(signType theSign = plus,
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