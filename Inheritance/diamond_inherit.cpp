/*  菱形继承问题
*   a -> b -> d
*     \> c />
*   d同时继承自b和c，那么d就无法区分b和c中的a成员
*   要么加上作用域
*   要么使用虚继承
*/

#include <iostream>
#include <string>
using namespace  std;

class person
{
public:
    person(/* args */);
    ~person();
    string _name;
};

person::person(/* args */)
{
}

person::~person()
{
}

class student : virtual public person
{
public:
    student(/* args */);
    ~student();
protected:
    int _num;
};

student::student(/* args */)
{
}

student::~student()
{
}

class teacher : virtual public person
{
public:
    teacher(/* args */);
    ~teacher();
    int _id;
};

teacher::teacher(/* args */)
{
}

teacher::~teacher()
{
}

class course : public teacher , public student
{
public:
    course(/* args */);
    ~course();
    string _major;
};

course::course(/* args */)
{
}

course::~course()
{
}

void test01(void)
{
    course morning;
    morning.student::_name = "tom";
    morning.teacher::_name = "lili";
    cout << "course mornint 无法区分name这个成员继承自谁，需要加上作用域来声明" << endl;
}

void test02(void)
{
    course evening;
    evening._name = "who";
    cout << "虚继承解决菱形继承" << endl;
    cout << evening._name << endl;
}

int main(int argc, char const *argv[])
{
    //test01();
    test02();
    return 0;
}


