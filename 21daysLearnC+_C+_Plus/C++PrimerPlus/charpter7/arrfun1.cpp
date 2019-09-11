// arrfun1.cpp -- functions with an array argument
#include <iostream>
const int ArSize = 8;

int sum_arr(int arr[], int n); // prototype
//int sum_arr(int *arr,int n)  //也可以这么写

int main()
{
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    // some systems require preceding int with static to
    // enable array initialization

    int sum = sum_arr(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << "\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
//arr实际上并不是数组而是一个指针！为了使函数通用，还需要传入长度
int sum_arr(int arr[], int n)  
{
    int total = 0;

    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total;
}

//函数如何通过指针处理数组
//c++将数组名解释为其第一个元素的地址
//cookies == &cookies[0]
//注意：对数组名使用sizeof将得到整个数组的长度（字节为单位），&cookies将返回一个32字节内存块地址

// arr[i] == *(ar + i)  //values in two natations
// &arr[i] == ar + i  //address in two notations
//将指针+1，实际上是加上一个与指针指向类型相等长度的值，对于数组而言，指针加法与数组下标相加等效

//注意函数传递参数使用是变量的拷贝
//而数组因为传递的是地址，即使用原数组
