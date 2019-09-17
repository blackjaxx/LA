//统一的初始化语法
int arr[] = {1, 2, 3}; //c++98

vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(3); //逐一添加元素

//c++11
vector<string> vec{1, 2, 3};
map<string, string> dict{{"ABC", "123"}, {"BCD", "234"}}; //map也可以这么初始化