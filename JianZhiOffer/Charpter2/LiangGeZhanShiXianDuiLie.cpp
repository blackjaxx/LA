//两个栈实现一个队列
//剑指offer第九题
//队列声明如下，请实现它的appendTail和deleteHead功能，完成队列尾部插入头部删除功能
#include <stack>

template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T &node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};
/*
思路：
定义类模板 类名CQueue 数据类型T
使用默认构造析构函数
生命appendTail和deleteHead方法
*/

//实现如下
template <typename T>
void CQueue<T>::appendTail(const T &element)
{
    stack1.push(element); //队尾添加元素相当于在第一个栈中压栈
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0) //第二个栈中元素
    {
        while (stack1.size() > 0) //必须将栈1中的元素全部压入栈2中，否则栈一中在进入元素1
        {
            T &data = stack1.top(); //临时引用，弹出的元素进入栈2 想想 * 行不行
            stack1.pop();
            stack2.push(data);
        }
    }

    if (stack2.size() == 0)
    {
        throw new exception("queue is empty"); //提示栈2空了
    }

    T head = stack2.top(); //栈2有元素 必须都弹出来
    stack2.pop();

    return head; //返回这个队列的头
}

/*

类型别名：
    一种方式使用预处理器：
    #define BYTE char  //编译的时候使用char替换所有的BYTE ，使BYTE成为char的别名
    另一种是使用typedef
    typedef typeName aliasName;
    typedef能处理更复杂的类型，不会创建新的数据类型，使用此关键字更佳
*/



//变形题，两个队列实现一个栈