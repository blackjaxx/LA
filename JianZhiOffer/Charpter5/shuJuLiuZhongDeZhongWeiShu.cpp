//数据流中的中位数
//剑指offer第41题
//如何得到一个数据流中的中位数，如果数据流读出数据是奇数的，那么中位数就是所有数值排序后位于中间的数值
//如果是偶数个，那么中位数就是数值排序后位于中间两个数的平均值
//如果使用未排序的数组，可以使用前面快速排序一趟的函数找到中位数，但是在没有排序数组中插入元素和找出中位数的时间复杂度分别是O(1),O(n)
//如果插入排序的数组，那么需要移动元素，插入的时间复杂度是O(n),找出中位数的时间复杂度为O(1)
//如果使用排序的链表，插入元素时间复杂度为O(n)，使用两根指针，得到中位数的时间复杂度为O(1)
//二叉搜索树可以把插入元素时间复杂度降低到O(logn)，但是二叉树不平衡时会退化成链表，二叉搜索树得到中位数，可以在节点中添加表示子节点数目的字段
//时间复杂度为平均O(logn)

//如果时大顶堆，那么父节点的值大于或等于子节点的值，但是子节点不一定排序
/*

用来创建堆的函数定义在头文件algorithm中，max_heap()对随机访问迭代器指定的一段元素重新排列，生成一个堆。默认使用的是<运算符，可以生成一个大顶堆；

std::vector<double>numbers{2.5 , 10.0 , 3.5 , 6.5 , 8.0 , 12.0 , 1.5 , 6.0 };
std::make_heap(std::begin(numbers), std:rend(numbers));
// Result: 12  10  3.5  6.5  8  2.5  1.5  6
*/

//在底层，一个 priority_queue 实例创建了一个堆；
//为什么STL有priority_queue(它是一个堆)，却还需要创建堆，特别是还需要将堆作为优先级队列？
//这是因为priority_queue可以提供堆没有的优势，它可以自动保持元素的顺序；但我们不能打乱priority_queue的有序状态，因为除了第一个元素，我们无法直接访问它的其他元素。
//如果需要的是一个优先级队列，这一点非常有用。

/*

从另一方面来说，使用 make_heap() 创建的堆可以提供一些 priority_queue 没有的优势：
可以访问堆中的任意元素，而不限于最大的元素，因为元素被存储在一个容器中，就像是我们自己的 vector。
这也提供了偶然破坏元素顺序的可能，但是总可以调用 make_heap() 来还原堆。
可以在任何提供随机访问迭代器的序列容器中创建堆。
这些序列容器包括普通数组、string对象、自定义容器。这意味着无论什么时候需要，都可以用这些序列容器的元素创建堆，必要时，可以反复创建。
甚至还可以为元素的子集创建堆。

*/

//堆不是容器，而是组织容器元素的一种特别方式

