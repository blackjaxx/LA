//包含MIN函数的栈
//定义栈的数据结构，请在其中实现一个能得到最小元素的MIN函数，在该栈中，调用min,pop,push的时间复杂度都是O（1）
//定义m_data是数据栈，m_min是辅助站
#include <stack>

template <typename T>
void StackWithMin<T>::push(const T &value)
{
    m_data.push(value);

    if (m_min.size() == 0 || value < m_min.top())
    {
        m_min.push(value); //输入元素比辅助栈中最小值还小，或者辅助栈中没有元素
    }
    else
    {
        m_min.push(m_min.top());
    }
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min_size() > 0);

    m_data.pop();
    m_min.pop();
}

template <typename T>
const T &StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

//模板的理解