//容器for的循环
//以前去遍历一个容器，比如集合
vector<int> vec;
for (vecor<int>::iterator it = vec.begin(); it != vec.end(); it++)
{
    *it += 2;
    cout << *it << endl;
}

//c++11中可以这么写
for (const auto &p : vec)
{
    cout << p << endl;
}

//如果要修改容器中的内容
for (auto &p : vec)
    p += 2;
//所有容器，map string deque list array都可以这样遍历