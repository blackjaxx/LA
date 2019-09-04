/*
伪代码：
char s[20];
int count = 0;
scanf("%s",s);
for (int abc = 111; abc < 999; abc++)
{
    for(int de = 11; de < 99; de++)
        if("abc是一个合法的竖式")
        {
            printf("%d",count);
            打印后边的空行
            count++；
        }
}
print();
*/

//竖式问题：
#include <cstdio>
int main()
{
    int count = 0;
    printf("%d %d %d", count++, count++, count++);
}