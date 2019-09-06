//翻转字符串
//剑指offer第58题
//题一：翻转单词顺序
//输入一个英文句子，反转句子中单词的顺序，但每一个单词内的顺序是不变的
//例： I am a student
// student a am I
void Reverse(char *pBegin, char *pEnd) //此函数翻转字符串内所有字符
{
    if (pBegin == nullptr || pEnd == nullptr)
    {
        return;
    }
    while (pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}

//接下来反转句子中的每个单词

char *ReverseSentence(char *pData)
{
    if (pData == nullptr)
    {
        return nullptr;
    }

    char *pBegin = pData;

    char *pEnd = pData;
    while (*pEnd != '\0')
        pEnd++;
    pEnd--;

    //反转整个句子
    Reverse(pBegin, pEnd); //为什么会用到这两个参数，因为输入的*pData长度是不确定的，所以需要前面遍历一下找到字符串开始和结束的位置

    //翻转句子中的每一个单词
    pBegin = pEnd = pData;
    while (*pBegin != '\0')
    {
        if (*pBegin == ' ')
        {
            pBegin++;
            pEnd++;
        }
        else if (*pEnd == ' ' || *pEnd == '\0')
        {
            Reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else
        {
            pEnd++; // pBegin不是空格且不是最后\0，且pEnd还有值
        }
    }
    return pData;
}