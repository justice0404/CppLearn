/* 深拷贝中如何正确的拷贝动态对象
*   应该给每个动态对象开辟一片独立的堆空间
*   新开辟的堆空间，里面通过值传递拷贝对应的值
*/

#include <iostream>

class Box_climb
{
private:
    int _len;
    int *p;
public:
    Box_climb(/* args */);
    Box_climb(const Box_climb& a);
    ~Box_climb();
};

Box_climb::Box_climb(/* args */)
{
    p = new int(100);
    std::cout << "P_Value:" << *p << std::endl;
}

Box_climb::Box_climb(const Box_climb& a)
{
    _len = a._len;
    //将a中p指针指向的堆内存中所存储的值拷贝过来，而不是浅拷贝的p = a.p简单的地址传递
    p = new int(*(a.p));
    std::cout << "拷贝的P_Value:" << *p << "\n被拷贝的P_Value:" << *(a.p) << std::endl;
}


Box_climb::~Box_climb()
{
    delete p;
}

int main(int argc, char const *argv[])
{
    Box_climb a;
    Box_climb b(a);
    return 0;
}

