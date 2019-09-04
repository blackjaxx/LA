//顺时针打印矩阵
//剑指offer第29题
//输入一个矩阵，按照从外向里顺时针顺序依次打印每个数字
/*例如矩阵如下：
    1  2  3  4
    5  6  7  8
    9 10 11 12
    13 14 15 16
*/
#include <cstdio>
//考虑清楚边界条件
//可以看作是若干个顺时针的圈套成的
//因为第一个要打印的元素坐标是（0，0），打印完这圈之后，在打印内一圈，坐标起始为（1，1）
//所以起始坐标为（start，start）

//例如5*5的矩阵，最后一圈只有一个数字，坐标是（2，2）
//6*6的矩阵，最后一圈有4个元素，起始坐标也是（2，2）
//则循环继续的条件是colums >startX*2,且 rows > startY*2

void PrintMartixClockwisely(int **numbers, int columns, int rows)
{
    if (numbers == nullptr || columns <= 0 || rows <= 0)
    {
        return;
    }

    int start = 0;

    while (columns > start * 2 && rows > start * 2)
    {
        PrintMartixInCircle(numbers, columns, rows, start); //打印一圈矩阵

        ++start;
    }
}

//考录打印一圈的功能，
//第一步从左到右打印一行
//从上到下打印一列
//从右到左打印一行
//从下到上打印一列
//每一步根据起始坐标和终止坐标用一个循环解决问题

//其中还有一个问题，就是打印最内一圈，如果只有一行，那么只需要第一步
//如果需要第二步的前提条件是终止行号大于起始行号
//需要第三步的情况是至少有两行两列，除了终止行大于起始行，终止列要大于起始列

void PrintMartixInCircle(int **numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    for (int i = start; i <= endX; ++i)
    {
        int number = numbers[start][i];
        printNumber(number);
    }

    if (start < endY)
    {
        for (int i = start + 1; i <= endY; ++i)
        {
            int number = numbers[i][endY];
            printNumber(number);
        }
    }

    if (start < endX && start < endY) //从右到左打印一行
    {
        for (int i = endX - 1; i >= start; --i)
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    if (start < endX && start < endY - 1) //从下到上打印一行
    {
        for (int i = endY - 1; i > start + 1; --i)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void printNumber(int number)
{
    printf("%d", number);
}