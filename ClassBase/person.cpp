/*
*   一个基本的类与对象的使用方法
*/

#include <iostream>
#include <string>
class person
{
private:
    /* data */
    int _age;
    std::string _name; 
public:
    person(/* args */);
    person(int age , std::string name);
    ~person();
};

person::person(/* args */)
{
    std::cout << "Person类构建" << std::endl;
}

person::person(int age,std::string name)
{
    _age = age;
    _name = name;
    std::cout << "Person类构建，姓名：" << _name << "\n年龄：" << _age <<std::endl;
}

person::~person()
{
    std::cout << "Person类析构" << std::endl;
}

void test01(void)
{
    person a;
}

void test02(void)
{
    person a(18,"newbee");
}

int main(int argc, char const *argv[])
{
    test01();
    test02();

    system("pause");
    return 0;
}


