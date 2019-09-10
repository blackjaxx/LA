//实例化并使用 std::tuple

#include <iostream> 
#include <tuple> 
#include <string>
using namespace std;

template <typename tupleType>
void DisplayTupleInfo(tupleType &tup)
//模板函数 DisplayTupleInfo()演示了如何使用 tuple_size，它在编译阶段获得特定的std::tuple 实例化包含的元素数
{ 
    const int numMembers = tuple_size<tupleType>::value; 
    cout << "Num elements in tuple: " << numMembers << endl; 
    cout << "Last element value: " << get<numMembers - 1>(tup) << endl;
    //使用的 std::get 是一种访问元组中各个元素的机制，它使用从零开始的索引
} 

int main() 
{ 
    tuple<int, char, string> tup1(make_tuple(101, 's', "Hello Tuple!"));
    //tup1 包含三个成员，一个 int、一个 char 和一个 std::string
    DisplayTupleInfo(tup1); 

    auto tup2(make_tuple(3.14, false));
    //tup2 包含一个 double 成员和一个 bool 成员，它还通过关键字 auto 使用了编译器的类型自动推断功能
    DisplayTupleInfo(tup2);

    auto concatTup(tuple_cat(tup2, tup1)); // contains tup2, tup1 members 
    DisplayTupleInfo(concatTup);
    //contactTup实际上是一个包含 5 个成员的元素，它们的类型分别为 double、bool、int、char 和 string，这是使用模
    //板函数 std::tuple_cat 拼接的结果

        double pi;
    string sentence; 
    tie(pi, ignore, ignore, ignore, sentence) = concatTup;
    //std::tie 演示了如何将元组的内容拆封（复制）到对象中。我们使用了std::ignore 让 tie 忽略不感兴趣的元组成员
    cout<< "Unpacked! Pi: " << pi << " and \"" << sentence << "\"" << endl;

    return 0; 
}