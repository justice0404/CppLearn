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

    static int cnt;
    static void Getcnt(void);

    string _name;
    int _cover;
    void set_person_cover(int cover)
    {
        _cover = cover;
    }
    void get_cover(void)
    {
        cout << "Here are the person class number" << endl;
    }

    void Print(void)
    {
        cout << "this person:" << this << " name:" << this->_name << " age:" << this->_age << " heigh:" << this->_heigh << endl;
    }
protected:
    int _heigh;

};

person::person(/* args */)
{
    cout << "person构造调用" << endl;
    cnt++;
}

person::~person()
{
    cout << "person析构调用" << endl;
    cnt--;
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

    int _cover;
    void set_student_cover(int cover)
    {
        _cover = cover;
    }
    int get_cover(void)
    {
        cout << "Here are the student class number" << endl;
        return _cover;
    }
};

student1::student1(/* args */)
{
    cout << "student1构造调用" << endl;
    cnt++;
}

student1::~student1()
{
    cout << "student1析构调用" << endl;
    cnt--;
}

void test01(void)
{
    student1 tom;
    tom.set(2023,9,173,"tom");
    //印证了只能访问public成员，无法访问其他权限
    cout << "能访问的成员:" << tom._grade << "&" << tom._name << endl;
    tom.Print();

    //切片原则，子类赋值给父类
    person tom_father = tom;
    cout << "切片原则的赋值" << endl;
    tom_father.Print();
}

void test02(void)
{
    student1 lisa;
    lisa.set(2024,9,163,"lisa");
    //父类自己的get_cover
    person lisa_father = lisa;
    lisa_father.get_cover();
    //lisa的get_cover只有一个，就是她自己的，已经覆盖了父类的
    lisa.set_student_cover(16);
    lisa.get_cover();
}

int person::cnt = 0;

void person::Getcnt(void)
{
    cout << "当前对象个数为：" << cnt << endl;
}

void test03(void)
{
    student1 one;
    one.Getcnt();
    student1 two;
    two.Getcnt();
    person three;
    three.Getcnt();
}

int main(int argc, char const *argv[])
{
    //test01();
    //test02();
    test03();
    return 0;
}


