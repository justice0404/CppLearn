/*  拷贝构造函数的学习
*   语法：Box::Box(const Box& a)
*
*   三种时机会调用拷贝构造函数：    
*   1.当一个对象作为函数参数，以值传递的形式传入函数体          void get_fcn(Box a)
*   2.一个对象作为函数的返回值，以值传递的形式从函数中返回      Box get)fcn(void)
*   3.一个对象用于给另外一个对象初始化                         Box b = a;  /  Box b(a);
*
* */


#include <iostream>

class Box
{
private:
    /* data */
    int _length;
    int _breadth;
    int _height;
public:
    Box(/* args */);
    Box(int length,int breadth,int height);
    //拷贝构造函数
    Box(const Box & a);
    ~Box();
};

Box::Box(/* args */)
{
    std::cout << "构造函数调用" << std::endl;
}

Box::Box(int length,int breadth,int height)
{
    std::cout << "赋值的构造函数调用" << std::endl;
    _length = length;
    _breadth = breadth;
    _height = height;
    std::cout << "len-" << _length << " bre-" << _breadth << " hei-" << _height << std::endl;
}

Box::Box(const Box & a)
{
    _length = a._length;
    _breadth = a._breadth;
    _height = a._height;
    std::cout << "拷贝构造函数调用" << std::endl;
}

Box::~Box()
{
    std::cout << "析构函数调用" << std::endl;
}

void get_fcn(Box a)
{
    std::cout << "GetFunction:" << std::endl;
}

Box get_fcn(void)
{
    Box temp(0,0,0);
    return temp;
}

void test01(void)
{
    Box tom(4,5,6);
    get_fcn(tom);
}

void test02(void)
{
    Box temp = get_fcn();
}

void test03(void)
{
    Box a(4,5,6);
    Box b(a);
    Box c = a;
}

int main(int argc, char const *argv[])
{
    /* code */
    //test01();
    //test02();
    test03();
    return 0;
}

