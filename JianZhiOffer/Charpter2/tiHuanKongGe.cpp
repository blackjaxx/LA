//替换空格
//剑指offer第五题
//实现一个函数，把字符串中每一个空格替换为%20
//输入we are happy 输出 we%20are%20happy

//如果我们在原字符串进行替换，可能覆盖后边的字符，如果在创建新的字符串并在新的字符串上进行替换，那么我们可以为自己分配足够多的内存

//从前向后替换的时间复杂度为O（n*2），我们从后向前移动，并使用两根指针，复杂度变为O（n）
void ReplaceBlank(char string[], int length)
{
    //length为字符数组的总容量
    if (string == nullptr || length <= 0)
    {
        return;
    }

    int originalLength = 0; //字符串长度
    int numberOfBlank = 0;  //空格数目
    int i = 0;

    while (string[i] != '\0')
    {
        ++originalLength;

        if (string[i] == ' ')
        {
            ++numberOfBlank;
        }

        ++i;
    }
    int newLength = originalLength + numberOfBlank * 2; //newlength是把空格替换为%20的长度
    if (newLength > length)
    {
        return; ///?????????????????????
    }

    int indexOfOriginal = originalLength; //指向原字符串的最后一位  \0
    int indexOfNew = newLength;           //指向增加%20后的字符串的最后一位

    while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if (string[indexOfOriginal] == ' ')
        {
            string[indexOfNew--] = '\0';
            string[indexOfNew--] = '2';
            string[indexOfNew--] = '%';
        }
        else
        {
            string[indexOfNew--] = string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}

/*
思想：




*/

/*
C-风格的字符串比较问题：
    如果word是数组名
    字符串“mate”
    我要比较字符数组中的字符串是不是mate
    word == "mate"
    这样的比较，数组名是数组的地址，引号中的字符串常量也是其地址，使用==是比较其是否存储在相同地址上
    而不是比较其值是否相等
    应该使用strcmp(),此函数接受两个字符串地址作为参数，具体返回值等看api去，查google
string类字符串，比较起来相对简单一些，提供关系运算符比较，因为类中重载了这些运算符

 */

/*

for和while可以互相改写

*/