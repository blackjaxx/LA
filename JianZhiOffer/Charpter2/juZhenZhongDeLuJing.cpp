//矩阵中的路径
//剑指offer12题
//使用回溯法
//回溯法解决问题的过程可一看做一个树状图，适合用递归实现代码，实现所有可能情况下递归抵达下一个节点；
/*
matrix = {a,b,t,g
          c,f,c,s
          j,d,e,h}

在此路径下包含一条bfce的路径
不包含abfb路径；因为第一个字符b占据了矩阵中的第一行第二个格子后，路径不能在进入这个格子；

*/
#include <cstring> //memset

bool hasPath(char *matrix, int cols, int rows, char *str)
{
    if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
    {
        return false;
    }

    bool *visited = new bool[rows * cols]; //定义和矩阵一样大小的格子，来确定是否访问过元素，因为路径不能重复进入格子
    memset(visited, 0, rows * cols);       //此函数经常在socket中用于清空数组，第一个参数是目标数组或指针，第二个是要重置的元素，第三个是visited的长度

    int pathLength = 0;
    for (int row = 0; row < rows; ++row)
    {
        for (int col = 0; col < cols; ++col)
        {
            if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
            {
                return true;
            }
        }
    }
    delete[] visited;
    return false;
}

bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char *str, int &pathLength, bool *visited)
{
    if (str[pathLength] == '\0')
    {
        return true; //说明搜到了字符串的路径
    }
    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
    {
        ++pathLength;
        visited[row * cols + col] = true;

        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited) ||
                  hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited);

        if (!hasPath)
        {
            --pathLength;
            visited[row * cols + col] = false;
        }
    }

    return hasPath;
}

/*
思路：

*/