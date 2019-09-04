//找出数组中的重复数字
//长度为N的数组中所有数字都在0 - N-1 范围内，数组中的数字某些重复但不知道哪些重复，也不知道重复几次，找出任意一个重复数字；
//若输入长度为7的数组{2,3,1,0,2,5,3}则输出的重复数字是2或3；

//思路：
//1.使用快速排序对数组进行排序
//2.使用hash表，时间复杂度为O（n），需要空间复杂度为O（n）；
//3.时间复杂度O（n）解法

bool duplication(int *duplication, int numbers[], int length)
{
    if (numbers == nullptr || length <= 0)
    {
        return false;
    }

    for (int i = 0; i < length; i++)
    {
        if (numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }

    for (int i = 0; i < length; i++)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            else
            {
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
    }
    return false;
}

/*
    for(initialization;test-expression;update-expression)
    {
        body
    }
    执行顺序：
    1.设置初始值
    2.执行测试，看是否应当继续执行，c++中，test-expression值不是只能为真或假，别的数据类型会被转换为bool类型
    3.执行循环操作
    4.更新用于测试的值 update-expression
    如果test-expression判断false，不执行循环体

 * /
/*
基于范围的for循环：
C++11中新增加的一种循环，对于数组，或容器类的每个元素都执行相同操作

double arr[5] = {4.99 , 10.99 , 6.87 , 7.99 , 8.49};
for(double x : arr)
    cout << x << std::endl;

也可以这么用：
for(int x : {1,2,3,4,5})
    cout << x << "";
cout << '\n'

*/

//变形题
//不修改数组找出重复的数字



/*
break和continue

for(int i = 0;line[i] != '\0';i++)
{
    cout << line[i];
    if(line[i] == '.')
        break;
    if(line[i] == ' ')
        continue;
    
    space++;
}
如上所示，continue会跳过循环体剩余部分但不会跳过循环更新表达式

也可以使用goto替代，但是尽量不要使用goto语句（c/c++都支持goto）
*/