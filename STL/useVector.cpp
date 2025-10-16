#include <iostream>
#include <vector>

using namespace std;

void test01(void)
{
    vector<int> arr(10,1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.pop_back();
    arr.resize(20,5);

    arr.resize(15);

    vector<int>::iterator it = arr.begin();
    while(it != arr.end())
    {
        cout << *it << endl;
        it++;
    }

    cout << "---------------------分界线---------------------------" << endl;

    vector<int>::reverse_iterator it_r = arr.rbegin();
    while (it_r != arr.rend())
    {
        /* code */
        cout << *it_r << endl;
        it_r++;
    }
    
}


/**   迭代器iterator的使用
*   将迭代器理解为一个智能指针 auto / vector<int>::iterator类型 
*   在vector<int>中就相当于int *型
*   解引用*it -- 代表当前这个位置的数值
*   it + x --当前迭代器后面x个位置
*   arr.begin() -- 返回数组第一个元素的迭代器
*   arr.end() -- 返回数组最后一个元素“之后”的迭代器
*   arr.erase(it) -- 删除当前的迭代器，并且it后移一位

**    迭代器iterator的失效
*   如果迭代器指向了数组不存在的内存，迭代器会失效
*   e.g.  arr = {0,1,2,3}
*   则it有效的范围为 arr.begin() ~ arr.begin()+3 ,不能指到arr.eng()这个尾后指针处
*/
void test02(void)
{
    vector<int> arr(10);
    int i = 1;
    vector<int>::iterator it;
    for(it=arr.begin();it!=arr.end();++it)
    {
        *it = i++;
    }


    for(it=arr.begin();it!=arr.end();)
    {
        if(*it % 2 == 0)
        {   
            //将当前位置的it去除，然后it重新指向下一个位置，即it++
            it = arr.erase(it);
        }
        else{
            it++;
        }
    }
   

    for(it=arr.begin();it!=arr.end();)
    {
        cout << *it << endl;
        it++;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    //test01();
    test02();
    return 0;
}
