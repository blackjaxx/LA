//机器人的运动范围
//剑指offer第13题
//地上有一{M,N}方格，一个机器人从坐标（0，0）开始移动，每次可以向上下左右移动一格，但是不能进入行坐标和列坐标之和大于K的格子
//比如K=18 ，机器人能进入方格（35，37），因为3+5+3+7 = 18，但是不能进入（35，38），因为3+5+3+8 = 19，请问机器人能到达多少格子（范围）；
//回溯法

//check用来判断机器人能否进入坐标（row，col）的方格
bool check(int threshold, int rows, int cols, int row, int col, bool *visited)
{
    if (row >= 0 && row < rows && col >= 0 && col < cols && getDigutSum(row) + getDigutSum(col) <= threshold && !visited[row * cols + col])
    {
        return true;
    }
    return false;
}

//getDigitSum用来得到一个数字位数之和
int getDigutSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum = sum + number % 10; //循环取余，先取个位
        number = number / 10;    //利用int的特性 比如22 / 10 = 2，number娶到了10位上的数字
    }

    return sum;
}

//能到达多少格子
int movingCountCore(int threshold, int rows, int cols, int col, int row, bool *visited)
{
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;

        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited) + movingCountCore(threshold, rows, cols, row + 1, col, visited) + movingCountCore(threshold, rows, cols, row, col - 1, visited)

                + movingCountCore(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}