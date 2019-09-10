
//在 vector 中查找元素及其位置
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> intArray;
    
    intArray.push_back(50);
    intArray.push_back(2991);
    intArray.push_back(23);
    intArray.push_back(9999);

    cout << "The contents of the vector are: " << endl;

    vector<int>::iterator arrIterator = intArray.begin();
    //迭代器初始化并将其初始化为指向容器开头，即 vector 的成员函数 begin() 返回的值
    //auto arrIterator = intArray.begin (); // compiler detects type   c++11

    while (arrIterator != intArray.end())
    {
        cout << *arrIterator << endl;
        ++arrIterator;
    }
    //如何在循环中使用该迭代器遍历并显示 vector 包含的元素，这与显示静态数组的内容极其相似

        vector<int>::iterator elFound = find(intArray.begin(), intArray.end(), 2991);
        //find 操作的结果也是一个迭代器，通过将该迭代器与容器末尾进行比较，可判断find是否成功if(elFound != intArray.end())
        {
            int elPos = distance(intArray.begin(), elFound);
            //注意distance两个参数代表什么，返回代表什么
            cout << "Value " << *elFound;
            cout << " found in the vector at position: " << elPos << endl;
            //如果找到了元素，便可对该迭代器解除引用（就像对指针解除引用一样）以显示该元素；算法distance计算找到的元素的所处位置的偏移量
    }
    return 0;
}
//所有的 vector 都替换为 deque，代码仍能通过编译并完美地运行；这表明迭代器让您能够轻松地使用算法和容器