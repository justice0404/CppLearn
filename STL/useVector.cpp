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

int main(int argc, char const *argv[])
{
    /* code */
    test01();
    
    return 0;
}
