//矩阵链乘
//输入n个矩阵的维度和一些矩阵链乘表达式，输出乘法的次数，如果乘法无法进行，输出error
//假定A是m*n矩阵，B是n*p矩阵，乘法次数为m*n*p
//A的列数不等于行数，乘法无法进行
//表达式比较简单的话可以用栈完成，遇到字母入栈，遇到右括号出栈计算，结果入栈，因为输入保证合法，所以括号无需入栈

#include <cstdio>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

struct Matrix
{
    int a, b;
    Matrix(int a = 0, int b = 0) : a(a), b(b) {}
} m[26];

stack<Matrix> s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;
}