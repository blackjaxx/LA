//序列化和反序列化二叉树
//剑指offer37题
//实现两个函数，序列化反序列化
//参见剑指offer第7题，当遍历二叉树的时候遇到nullptr时，这些指针将序列化为一特殊字符如$
#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    double m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

//序列化过程
void Serialize(BinaryTreeNode *pRoot, ostream &stream)
{
    if (pRoot == nullptr)
    {
        stream << "$";
        return;
    }

    stream << pRoot->m_nValue << ",";
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

//反序列化
void Deserialize(BinaryTreeNode **pRoot, std::istream &stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;

        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}

//ReadStream函数
bool ReadStream(istream &stream, int *number)
{
    if (stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while (!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if (i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}
