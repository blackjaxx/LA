// arrfun4.cpp -- functions with an array range
#include <iostream>
const int ArSize = 8;
int sum_arr(const int *begin, const int *end);  //使用区间的数组
int main()
{
    using namespace std;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    //  some systems require preceding int with static to
    //  enable array initialization

    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten: " << sum << endl;
    sum = sum_arr(cookies, cookies + 3); // first 3 elements
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + 8); // last 4 elements
    cout << "Last four eaters ate " << sum << " cookies.\n";
    // cin.get();
    return 0;
}

// return the sum of an integer array
int sum_arr(const int *begin, const int *end)
{
    const int *pt;
    int total = 0;

    for (pt = begin; pt != end; pt++)
        total = total + *pt;
    return total;
}


//注意不同函数调用是如何指定不同区间的
//int sum = sum_arr(cookies,cookies+ArSize);  //整个数组
//sum = sum_arr(cookies, cookies + 3);
//sum = sum_arr(cookies + 4,cookies + 8);

//cookies + ArSize指向最后一个元素后边的一个位置（cookies[ArSize - 1]是最后一个元素，地址为cookies + ArSize -1）

//指针和const
//分为两种，如果指针指向常量对象，那么不可改变常量对象的值
//int age = 39;
//const int *pt = &age;
//*pt的值为const，不可被修改

//指针使用const有几种复杂的情况

//函数和二维数组
//int data[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
//int total = sum(data,3);
//data是一个数组名，该数组有三个元素，每个元素又是一个数组，因此data是指向由4个int组成的数组的指针
//int sum(int (*ar2)[4],int size);
//另一种原型声明 int sum(int ar2[][4],int size);

//注意ar2 + r指向编号为r的元素
//ar2[r][c] == *(*(ar2 + r) + c)  //两次解引用

