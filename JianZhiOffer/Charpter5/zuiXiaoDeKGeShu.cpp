//最小的K个数
//剑指offer第40题
//输入n个整数，找出其中最小的k个数
//例：4，5，1，6，2，7，3，8，则最小的4个数字是1，2，3，4；

//最简单的想法把输入的整数k进行排序，排序之后位于最前面k个数就是最小的k个数，时间复杂度位O（nlogn）

//有一种解决办法，基于数组第k个数字进行调整，比k个数字大的数字都位于数组的右边，比k个数字小的数字都位于左边（不一定是排序的）

void GetLeastNumbers(int *input, int n, int *output, int k)
{
    if (input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
    {
        return;
    }

    int start = 0;
    int end = n - 1;
    int index = Partition(input, n, start, end);
    while (index != k - 1)
    {
        if (index > k - 1) //基于第k个数字进行调整
        {
            end = index - 1;
            index = Partition(input, n, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(input, n, start, end);
        }
    }
    for (int i = 0; i < k; i++)
    {
        output[i] = input[i];
    }
}

int Partition(int data[], int length, int start, int end)
{
    return 0; //具体参考快速排序代码，第二章；
}

//如果不允许修改数组，那么需要采用其他方法
//时间复杂度为O（nlogk）的算法，适合处理海量数据
//我们可以创建大小为k的容器存储最小的k个数字，接下来每次从输入的n中读入一个数；如果容器中少于k个数，直接将读入的数放入容器内，容器如果满了；
//则将次数和容器中最大值比较，如果小于，替换容器中最大值，否则直接舍弃；此时如果使用一颗二叉树存储数据，则增删一个元素时间复杂度为O（logk）；
//当容器满了之后要进行三步操作：
//1.在k个整数中找到最大数；
//2.有可能在这个容器中删除最大数；
//3.有可能要插入一个新元素；
//c++ STL中 set和muiltset都是基于红黑树实现的
#include <set>
#include <vector>
using namespace std;

typedef multiset<int,greater<int>> intSet;
typedef multiset<int, greater<int>>::iterator setIterator;  //第二个参数规定元素是降序排列的

void GetLeastNumbers(const vector<int> &data,intSet &leastNumbers,int k)
{
    leastNumbers.clear();  //清空k个数的容器

    if (k < 1 || data.size() < k)  //输入n个整数存储在vector中
    {
        return;
    }
    
    vector<int>::const_iterator iter = data.begin(); //迭代器创建
    for (; iter != data.end(); ++iter)
    {
        if (leastNumbers.size() < k)
        {
            leastNumbers.insert(*iter); //长度 < k  插入元素
        }
        else
        {
            setIterator iterGreatest = leastNumbers.begin(); //leastNumbers中的元素已经有序，降序

            if (*iter < *(leastNumbers.begin())) //因此只比较最大的那个头元素即可
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }       
        }
    }
}

//关于stl中的set

//定义 set 容器的模板如下：
//set<T> 容器保存 T 类型的对象，而且保存的对象是唯一的。其中保存的元素是有序的，默认用 less<T> 对象比较。可以用相等、不相等来判断对象是否相同;
//multiSet<T> 容器和 set<T> 容器保存 T 类型对象的方式相同，但它可以保存重复的对象;
//unorderd_set<T> 容器保存 T 类型的对象，而且对象是唯一的。元素在容器中的位置由元素的哈希值决定。默认用 equal_to<T> 对象来判断元素是否相等;
//unordered_multiset<T> 容器保存 T 类型对象的方式和 unorderd_set<T> 相同，但它可以保存重复的对象;
//初始化：set<T> numbers {1,2,3,4,5,6,7}
//默认的比较函数是 less<int>，因此容器中的元素会升序排列
//成员函数clear()会删除set的所有元素；成员函数 erase()会删除迭代器指定位置的元素或与对象匹配的元素
//然而，set容器的迭代器类型的别名有时会让人产生一些误解。所有set<T>容器的成员函数返回的迭代器都指向const T类型的元素。
//因此iterator迭代器会指向const元素，reverse_iterator和其他类型的迭代器也是如此。这意味着我们不能修改元素。如果想要修改set容器中的元素，必须先删除它，然后再插入修改后的版本。
//仔细思考一下，其实这是不合理的。set中的对象以它们自己作为键，对象在容器中的位置是通过比较对象决定的。如果可以修改元素，元素的顺序就失效了，也会扰乱后面的访问操作。
//当必须修改元素而且仍然需要将它们组合到一个或多个set容器中时，还有一个方法可以做到这一点。可以在set容器中保存指针，并且最好选择智能指针。
//当使用set容器时，通常会在它们中保存shared_ptr<T>或weak_ptr<T>对象。在 set 容器中保存unique_ptr<T>对象没有多少意义。因为容器中不存在和unique_ptr<T>对象匹配的独立键，所以我们从来不会直接检索元素。