/*  探究This指针的作用
*   类的存储结构中：
*   每个对象的非静态对象成员会各自存放在一个堆空间中，
*   一个类中所有的成员函数，统一存放在代码区
*   所有对象共享同一个代码区的成员函数
*
*   因此，为了区分到底是哪个对象调用了成员函数
*   可以使用this指针，指向当前调用的对象
*/

#include <iostream>

class Box_This
{
private:
    int _value;
public:
    Box_This(/* args */);
    ~Box_This();
    void SetValue(int value);
    int GetValue(void);
};

Box_This::Box_This(/* args */)
{
}

Box_This::~Box_This()
{
}

void Box_This::SetValue(int value)
{
    this->_value = value;
    std::cout << "Set This:" << this << " Value:" << this->_value << std::endl;
}

int Box_This::GetValue(void)
{
    std::cout << "This:" << this << " Value:" << this->_value << std::endl;
    return this->_value;
}


int main(int argc, char const *argv[])
{
    /* code */
    Box_This a;
    int temp;
    a.SetValue(100);
    temp = a.GetValue();
    std::cout << "Get Temp:" << temp << std::endl;
    return 0;
}
