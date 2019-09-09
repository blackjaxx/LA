//string分配器介绍
//配置器是STL的重要内容。使用STL必然会涉及容器，而容器中存储了大量的数值，必然需要分配内存空间。配置器的作用就是为容器分配内存。
//配置器最早是为将内存模型抽象化而提出的。所以使用内存配置器分配内存时，是按对象的个数进行的，而不是按字节数。
//这有别于原来的new[]和new操作符。配置器最大的优点在于，配置器实现了将算法、容器与物理存储细节分隔。配置器可以提供一套分配与释放内存的标准方式，并提供用作指针类型和引用类型的标准名称。
//目前而言，配置器仅是一种纯粹的抽象。行为上类似分配器的类型都可看作配置器。
//C++ STL 提供了标准分配器，目的是为用户提供更多的服务。basic_string 模板以及 string 类均提供了对常见配置器的相关支持。
//basic_string类模板中包含1个配置器类型的成员allocator_type。对于string对象，allocator_type可以作为配置器类的对象使用；对string类而言，allocator_type等价于allocator<char>
//即分配数据类型为char的内存，便于string类的对象存储char型字符。

//basic_string类模板的第3个参数也是配置器模板参数。basic_string类模板的形式如下：
//template <class CharType, class Traits = char_traits<CharType>, class Allocator = allocator<CharType>> class basic_string

//函数返回string类的内存模型对象，可以用于构造新的字符串。以如下程序为例介绍该函数的使用方法
#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main()
{
    string s("abed");
    basic_string<char> s1(s.get_allocator());
    basic_string<char>::allocator_type aT = s1.get_allocator();
    string::size_type se = s1.size();
    cout << se << endl;
    return 0;
}
