#include <iostream>

using namespace std;

class BaseClass
{
public:
    int BaseClass_public = 0;
private:
    int BaseClass_private = 0;
protected:
    int BaseClass_protected = 0;
};

class DerivedClassPublic: public BaseClass
{
public:
    BaseClass *bc_public = new BaseClass();
    int DerivedClass_public = 0;
private:
    int DerivedClass_private = 0;
protected:
    int DerivedClass_protected = 0;
};

class DerivedClassPrivate: private BaseClass
{
public:
    BaseClass *bc_public = new BaseClass();
    int DerivedClass_public = 0;
private:
    int DerivedClass_private = 0;
protected:
    int DerivedClass_protected = 0;
};

class DerivedClassProtected: protected BaseClass
{
public:
    BaseClass *bc_public = new BaseClass();
    int DerivedClass_public = 0;
private:
    int DerivedClass_private = 0;
protected:
    int DerivedClass_protected = 0;
};

int main(int argc, char const *argv[])
{
    {
        BaseClass *bc = new BaseClass();
        cout << bc->BaseClass_public << endl;
        // cout << bc->BaseClass_private << endl;      // 对象不能直接访问类的私有成员
        // cout << bc->BaseClass_protected << endl;    // 对象不能直接访问类的保护性成员
    }

    {
        // 无法将派生类初始化为基类对象
        // DerivedClassPublic *dc_public = new BaseClass;
        // DerivedClassPrivate *dc_private = new BaseClass;
        // DerivedClassProtected *dc_private = new BaseClass;
    }

    {
        // 将基类初始化为派生类对象
        BaseClass *bc = new DerivedClassPublic();
        cout << bc->BaseClass_public << endl;
        // cout << bc->BaseClass_private << endl;      // 对象不能直接访问类的私有成员
        // cout << bc->BaseClass_protected << endl;    // 对象不能直接访问类的保护性成员
 
    }

    {   // 派生类对象无法直接访问基类private, protected成员
        DerivedClassPublic *dc_public = new DerivedClassPublic();
        cout << dc_public->bc_public->BaseClass_public << endl;
        // cout << dc_public->bc_public->BaseClass_private << endl;
        // cout << dc_public->bc_public->BaseClass_protected << endl;
    }

    {
        DerivedClassPrivate *dc_private = new DerivedClassPrivate();
        cout << dc_private->bc_public->BaseClass_public << endl;
        // cout << dc_private->bc_public->BaseClass_private << endl;
        // cout << dc_private->bc_public->BaseClass_protected << endl;
    }

    {
        DerivedClassProtected *dc_protected = new DerivedClassProtected();
        cout << dc_protected->bc_public->BaseClass_public << endl;
        // cout << dc_protected->bc_public->BaseClass_private << endl;
        // cout << dc_protected->bc_public->BaseClass_protected << endl;
    }

    return 0;
}