//最长不含重复字符的子字符串
//剑指offer第48题
//动态规划
#include <string>
int longestSubstringWithoutDuplication(const std::string &str)
{
    int curLength = 0; //当前不重复长度
    int maxLength = 0; //最大长度

    int *position = new int[26];
    for (int i = 0; i < 26; i++)
    {
        position[i] = -1; //使用长度为26数组，容纳26个字母，初始化为-1代表未出现过
    }

    for (int i = 0; i < str.length(); i++) //遍历字符串
    {
        int prevIndex = position[str[i] - 'a'];
        if (prevIndex < 0 || i - prevIndex > curLength) //未出现过字符或者出现字符与前距离d>f(i-1）
        {
            ++curLength;
        }
        else
        //出现过此字符
        {
            if (curLength > maxLength)
            {
                maxLength = curLength;
            }
            curLength = i - prevIndex;
        }
        position[str[i] - 'a'] = i;
    }
    if (curLength > maxLength)
    {
        maxLength = curLength;
    }
    delete[] position;
    return maxLength;
}