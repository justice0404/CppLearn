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

class student : public person
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

class teacher : public person
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

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}


