//类型推导auto
//例如比较长的类型声明
vector<int> vec;
vector<int>::iterator cit = vec.begin();

//c++11中
//auto cit = vec.begin();
//也支持引用类型的变量
vector<int> vec = {1, 2, 3};
auto v2 = vec[1];
v2 += 3; //vec变为{1,5,3}