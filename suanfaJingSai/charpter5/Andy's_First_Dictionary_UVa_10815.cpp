//andy的第一个字典
//输入一个文本，找出不同单词，按字典序从小到大输出
//使用set,由于string已经定义了 < 运算符，直接使用set保存单词即可，非字母字符变为空格，利用stringstream得到各个单词
#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

set<string> dict;

int main()
{
    string s, buf;
    while (cin >> s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i])) //isalpha函数判断输入的是不是字母
            {
                s[i] = tolower(s[i]); //全部转换成小写
            }
            else
            {
                s[i] = ' ';
            }
            stringstream ss(s); //创建临时对象，将整个s传递给ss
            while (ss >> buf)   //输出流中，ss所有字符串都被输出，以空格为分界，直到没有内容输出
            {
                dict.insert(buf); //插入对象dict的set中
            }
        }
    }
    for (set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
    {
        cout << *it << "\n"; //迭代器输出
    }
}

//本题利用了set中元素已经从小到大排好序这一性质；

//istringstream是由一个string对象构造而来，从一个string对象读取字符；
//ostringstream同样是有一个string对象构造而来，向一个string对象插入字符；
//stringstream则是用于C++ 风格的字符串的输入输出的

//1）在istringstream类中，构造字符串流时，空格会成为字符串参数的内部分界；
//2）istringstream类可以用作string与各种类型的转换途径；
//3）ignore函数参数：需要读取字符串的最大长度，需要忽略的字符；
//其余两类同理