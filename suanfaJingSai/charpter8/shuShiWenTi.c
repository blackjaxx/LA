/* 竖式问题。 找出所有形如abc * de（ 三位数乘以两位数） 的算式， 使得在完整的竖式中，
    所有数字都属于一个特定的数字集合。 输入数字集合（ 相邻数字之间没有空格） ， 输出所有
    竖式。 每个竖式前应有编号， 之后应有一个空行。 最后输出解的总数。 具体格式见样例输出
    (为了便于观察， 竖式中的空格改用小数点显示， 但所写程序中应该输出空格， 而非小数
    点） 。
*/

/*
样例输入：
2357
样例输出：
<1>
..775
X..33
-----
.2325
2325.
-----
25575
The number of solutions = 1
 */

/*
伪代码：
    char s[20];
    int count = 0;
    scanf("%s", s);
    for(int abc = 111; abc <= 999; abc++)
        for(int de = 11; de <= 99; de++)
            if("abc*de"是个合法的竖式)
                {
                    printf("<%d>\n", count);
                    打印abc*de的竖式和其后的空行
                    count++;
                }
    printf("The number of solutions = %d\n", count);
 */

#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char s[20], buf[99];
    scanf("%s", s);
    for (int abc = 111; abc <= 999; abc++)
        for (int de = 11; de <= 99; de++) //尝试所有组合
        {
            int x = abc * (de % 10), y = abc * (de / 10), z = abc * de;
            sprintf(buf, "%d%d%d%d%d", abc, de, x, y, z);
            int ok = 1;
            for (int i = 0; i < strlen(buf); i++)
                if (strchr(s, buf[i]) == NULL)
                    ok = 0;
            if (ok)
            {
                printf("<%d>\n", ++count);
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n", abc, de, x, y, z);
            }
        }
    printf("The number of solutions = %d\n", count);
    return 0;
}
