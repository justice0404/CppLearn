/* 探究浅拷贝可能会带来的问题
*   当类中存在静态成员或是动态成员时，
*   不能再单纯的使用浅拷贝，
*   这会导致静态或动态成员没有独享一片堆空间，
*   程序无法对其进行正确的操作。
*
*   正确的处理静态对象，应该对其进行单独处理
*/

#include <iostream>

class Box_step
{
private:
    int _len;
    int _width;
    static int cnt;
public:
    Box_step(/* args */);
    Box_step(const Box_step& a);
    ~Box_step();
    static int get_Cnt(void);
};

Box_step::Box_step(/* args */)
{
    cnt++;
}

Box_step::Box_step(const Box_step& a)
{
    _len = a._len;
    _width = a._width;
    cnt++;
}


Box_step::~Box_step()
{
    cnt--;
    std::cout << "析构函数调用，count:" << cnt << std::endl;
}

int Box_step::get_Cnt(void)
{
    return cnt;
}

int Box_step::cnt = 0;

int main(int argc, char const *argv[])
{
    Box_step a;
    std::cout << "The Count:" << Box_step::get_Cnt() << std::endl;
    Box_step b(a);
    std::cout << "The Count:" << Box_step::get_Cnt() << std::endl;
    return 0;
}

