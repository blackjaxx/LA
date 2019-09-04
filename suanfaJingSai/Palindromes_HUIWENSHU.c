/*
输入一个字符串， 判断它是否为回文串以及镜像串。 输入字符串保证不含数字0。 所谓
回文串， 就是反转以后和原串相同， 如abba和madam。 所有镜像串， 就是左右镜像之后和原串相同， 如2S和3AIAE。
注意， 并不是每个字符在镜像之后都能得到一个合法字符。

 */

/*
样例输入：

NOTAPALINDROME
ISAPALINILAPASI
2A3MEAS
ATOYOTA

样例输出：

NOTAPALINDROME -- is not a palindrome.ISAPALINILAPASI -- is a regular palindrome.
2A3MEAS -- is a mirrored string.
ATOYOTA -- is a mirrored palindrome.

【分析】
既然不包含空白字符， 可以安全地使用scanf进行输入。 回文串和镜像串的判断都不复
杂， 并且可以一起完成， 详见下面的代码。 使用常量数组， 只用少量代码即可解决这个看上
去有些复杂的题目

 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char *rev = "A 3 HIL JM O 2TUVWXY51SE Z 8 ";
const char *msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string"}

char
r(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[30];
    while (scanf("%s", s) == 1)
    {
        int len = strlen(s);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
                p = 0; //不是回文串
            if (r(s[i]) != s[len - 1 - i])
                m = 0; //不是镜像串
        }
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
    }
    return 0;
}