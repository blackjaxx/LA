//std::string 类实际上是 STL 模板类 std::basic_string <T>的具体化
//容器类 basic_string的模板声明如下
//template<class _Elem,class _Traits,class _Ax >class basic_string
//在该模板定义中，最重要的参数是第一个：_Elem，它指定了 basic_string 对象将存储的数据类型。 因此，std::string 使用_Elem = char 具体化模板 basic_string 的结果，
//而 wstring 使用_Elem = wchar 具体化模板 basic_string 的结果
//换句话说，STL string 类的定义如下
//typedef basic_string<char, char_traits<char>, allocator<char> >string;
//typedef basic_string<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >string;
//如果编写的应用程序需要更好地支持非拉丁字符，如中文和日文，应使用 std::wstring

//使用 C++14 引入的 operator “”s
#include<string> 
#include<iostream> 
using namespace std; 

int main() 
{ 
    string str1("Traditional string \0 initialization");
    //使用常规字符串字面量创建一个 std::string 实例。注意到这个字符串中间的空字符导致 str1根本不包含单词 initialization
    cout<< "Str1: " << str1 << " Length: " << str1.length() << endl;

    string str2("C++14 \0 initialization using literals"s);
    //使用了 C++14 引入的 operator “”s，这让实例 str2 能够包含并操作含有空字符的字符缓冲区
    cout << "Str2: " << str2 << " Length: " << str2.length() << endl; 
 
    return 0; 
}
//C++14 在 std::chrono 中引入了 operator “”s，如下所示
    //std::chrono::seconds timeInSec(100s); // 100 seconds
    //std::string timeinText = "100"s; // string "100"
//前者指出时间为 100 秒，是一个整型字面量；而后者的结果为字符串