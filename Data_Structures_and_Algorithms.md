[toc]

# 前言

​		这个文档是我后面学习数据结构与算法的内容笔记。 其中应该包含重要概念、重要知识点、代码段以及相关疑问等等，使用的书为**《数据结构、算法与应用（C++语言描述）》（原书第二版）**。



# 第一章 C++回顾

## 函数与参数

### 参数

1.   **传值参数**

     ```c++
     // 程序 1-1
     int abc(int a, int b, int c){
         return a + b * c;
     }
     
     z = abc(2, x, y);
     ```

     在程序 1-1中, a, b和c都是函数`abc`的**形参(formal parameter)**. 2, x, y是分别与a, b, c对应的**实参(actual paramater)**. 形参a, b, c实际上是**<font color=blue>传值参数(value parameter)</font>**. 在运行时, 函数`abc`执行前, 把实参复制给形参, 复制过程是由形参类型的**复制构造函数(copy constructor)**来完成的.

2.   **引用参数**

     ```c++
     // 程序 1-2
     template <class T>
     T abc(T& a, T& b, T& c){
     	return a + b + c;
     }
     
     z = abc(x, y, z);
     ```

     在程序 1-2中, a, b, c是**<font color=blue>引用参数(reference parameter)</font>**. 实参x, y, z分别是a, b, c的别名, 也就是在`abc`执行期间, 名字x, y, z分别代替了名字a, b, c. 与传值参数的情况不同, 当函数被调用时没有复制实参的值, 在函数返回时没有调用析构函数.

3.   **常量引用**

     **<font color=blue>常量引用(const reference)</font>**指明的引用参数不能被函数修改. 例如在程序 1-2中如果不想更改传入参数的值, 可以重写这段代码:

     ```c++
     // 程序 1-3
     template <class T>
     T abc(const T& a, const T& b, const T& c){
     	return a + b + c;
     }
     
     z = abc(x, y, z);
     ```

     另外, 程序 1-3更通用的[程序](./0001-C++_Review/0005-Template_Function_Plus.cpp)如下:

     ```c++
     // 程序 1-4
     template <class Ta, class Tb, class Tc>
     Ta abc(const Ta& a, const Tb& b, const Tc& c){
     	return a + b + c;
     }
     
     z = abc(x, y, z);
     ```

     



# 附录

## 中英文对照表

### 文件名自译部分

| 中文             | 英文                           |
| ---------------- | ------------------------------ |
| 模板函数         | Template_Function              |
| 结构体操作符重载 | Structure_Operator_Overloading |
| 引用参数         | Reference_Parameter            |
| 常量引用         | Const_Reference                |

