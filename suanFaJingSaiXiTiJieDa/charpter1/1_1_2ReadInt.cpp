//整数输入
//经常使用的是int数据类型，一般输入数据后存储到集合或数组中，一般做法是创建临时变量，使用cin或者scanf，中再将临时变量插入到集合中
//可以封装成输入函数
#include <iostream>
#include <vector>
using namespace std;

int readint()
{
    int x;
    scanf("%d", &x); //cin >> x
    return x;
}

vector<int> vc;
vc.push_back(readint());
//this declaration has no storage class or type specifier
//对变量的赋值一般不能放到函数外，只有在定义全局变量时的初始化才被允许！