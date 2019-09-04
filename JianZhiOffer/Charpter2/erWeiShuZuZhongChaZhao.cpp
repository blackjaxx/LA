//二维数组中的查找
//剑指offer第四题
//注意此题可以从右上角或者左下角开始查找，但是不能选取从左上角或右下角开始查找
bool Find(int *matrix, int rows, int columns, int number)
{
    //传入数组 行数 列数 要查找的元素 number
    bool found = false; //标志位是否查找到元素

    if (matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1; //当前列数

        while (row < rows && column >= 0)
        {
            if (matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if (matrix[row * columns + column] > number)
            {
                --column;
            }
            else
            {
                ++row;
            }
        }
    }
    return found;
}

/*
逻辑：

bool find(数组，行，列，查找元素)
{
    bool标志位 先设定为false;

    if（数组不空，边界条件）
    {
        int 临时行数
        int 临时列数，因为我要从右上角开始查找

        while(边界条件){

            if（数组元素 == 查找元素）
            {
                改变标志位true；
                break；
            }

            else if（数组元素 > 查找元素）
            {
                --列数 
            }

            else
            {
                ++行数
            }
        }
    }
    return 标志位

}
*/