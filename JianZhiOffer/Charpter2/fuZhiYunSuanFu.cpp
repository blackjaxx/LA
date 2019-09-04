//赋值运算符函数
//剑指offer第一题
//如下CMyString的声明，请为该类型添加赋值运算符函数 = 符号
#include <cstdio>
#include <string.h>

class CMyString
{
private:
    char *m_pData;

public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);
};

//1.是否把返回值类型声明为该类型的引用，并在函数结束前返回实例自身的引用（*this），只有返回引用，才能连续赋值
//2.能否把传入的参数声明为常量的引用，如果传入的是实例，从形参调用一次实参就会调用一次复制构造函数，传递引用可以避免无用的消耗
//3.防止内存泄漏
//4.判断传入参数和当前实例（*this）是不是用一个实例，如果是用一个，不进行赋值操作直接返回

CMyString &CMyString::operator=(const CMyString &str)
{
    if (this == &str)
    {
        return;
    }

    delete[] m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}

//考虑到异常安全性的解法
CMyString &CMyString::operator=(const CMyString &str)
{
    if (this != &str)
    {
        CMyString strTemp(str);

        char *pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }

    return *this;
}

/*

const关键字：



 * /
 

 /*
 
 bad_alloc异常
 
 
 */
