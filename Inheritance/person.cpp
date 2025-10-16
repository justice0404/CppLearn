/***   继承的基本特性
**   语法: class son : public father [, protected father1 ,private father2]
**   特性:
*   1.访问权限-
        继承方式public决定了继承过来的父类成员，在子类中充当public权限的成员
        无论哪种继承方式，子类都只能访问父类的public和protected
*   2.赋值-
        father对象 = son对象
        此类赋值遵循切片原则，将son对象中对应的成员赋值给father对象
        反之，如果son对象 = father对象，则不可以直接赋值，因为缺少相应的成员
*   3.作用域-
        同名变量-如果父类和子类拥有同名的变量，那么子类中对变量的调用将会使用子类而非父类的，即子类变量会覆盖父类
        同名函数-如果父类和子类拥有同名的函数，即使返回值、形参不同，也会形成覆盖
*   4.构造、析构函数
        子类和父类的构造、析构遵循一定的顺序：构造父类->构造子类->执行代码->析构父类->析构子类
        如果要修改这两个函数，千万不要在这其中随便调用父类子类的构造析构，以免改变这些顺序
*   5.默认成员函数
        包括：构造、析构函数；拷贝构造函数；赋值重载函数；取地址重载函数；
*   6.友元
        友元关系是一种单向的不可传递的关系，父类的友元不能继承到子类
*   7.静态成员
        静态成员的备份只有一个，无论继承到多少子类，始终只有一个静态成员
*/

#include <iostream>
#include <string>

using namespace std;

class person
{
private:
    int _age;
public:
    person(/* args */);
    ~person();
    string _name;

    void Print(void)
    {
        cout << "this person:" << this << " name:" << this->_name << " age:" << this->_age << " heigh:" << this->_heigh << endl;
    }
protected:
    int _heigh;
};

person::person(/* args */)
{
}

person::~person()
{
}

class student1 : public person
{
private:
    /* data */
    int _id;
public:
    student1(/* args */);
    ~student1();

    int _grade;
    //public继承
    //将继承过来的成员当作public成员
    //但是无论哪种继承，只能访问基类的public和protected的限制的成员
    void set(int id,int grade,int heigh,string name)
    {
        _id = id;
        _grade = grade;
        _heigh = heigh;
        _name = name;
    }
};

student1::student1(/* args */)
{
}

student1::~student1()
{
}

void test01(void)
{
    student1 tom;
    tom.set(2023,9,173,"tom");
    //印证了只能访问public成员，无法访问其他权限
    cout << "能访问的成员:" << tom._grade << "&" << tom._name << endl;
    tom.Print();
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}


