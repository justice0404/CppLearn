/*  静态成员
*   静态成员数据：
*   静态成员数据会存储到类的结构中，所有的对象共享
*   声明时的语法——static ElemType Name;
*   静态成员数据的初始化必须在类外，不受访问权限的限制
*   初始化时的语法——ElemType ClassName::Name = 0
*
*   静态成员函数：
*   静态成员函数只能访问静态成员数据，其他静态成员函数和类外的其他函数
*   静态成员函数没有this指针
*   静态成员函数和类在同一存储结构，不和某个对象有关
*
*/


#include <iostream>

class Box_static
{
private:
    /* data */
    int _len;
    int _width;
    static int _priCnt;
public:
    static int _pubCnt;
    Box_static(/* args */);
    ~Box_static();
    static int GetCnt(void);
    int GetVolume(void);
    void SetValue(int len,int width);
};

Box_static::Box_static(/* args */)
{
    _priCnt++;
    _pubCnt++;
    std::cout << "构造函数调用" << std::endl;
}

Box_static::~Box_static()
{
    _priCnt--;
    _pubCnt--;
    std::cout << "析构函数调用" << std::endl;
}

int Box_static::GetCnt(void)
{
    std::cout << "Pri:" << _priCnt << " Pub:" << _pubCnt << std::endl;
    return _priCnt+_pubCnt;
}

int Box_static::GetVolume(void)
{
    std::cout << "Volume:" << _len*_width << std::endl;
    std::cout << "Cnt:" << _priCnt << _pubCnt <<std::endl;
    return _len * _width;
}

void Box_static::SetValue(int len,int width)
{
    _len = len;
    _width = width;
}

int Box_static::_priCnt = 0;
int Box_static::_pubCnt = 0;

int main(int argc, char const *argv[])
{
    Box_static a;
    int temp;
    int Cnt;
    a.SetValue(4,5);
    temp = a.GetVolume();
    Cnt = a.GetCnt();
    return 0;
}

