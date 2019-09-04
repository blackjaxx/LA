/*
    在TeX中， 左双引号是“``”， 右双引号是“''”。 输入一篇包含双引号的文章， 你的任务是把它转换成TeX的格式。

样例输入：

"To be or not to be," quoth the Bard, "that
is the question".
样例输出：

``To be or not to be,'' quoth the Bard, ``that
is the question''.
 */

#include <stdio.h>
int main()
{
    int c, q = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else
            printf("%c", c);
    }
    return 0;
}