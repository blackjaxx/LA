//位运算操作封装
//使用位向量表示集合或状态压缩时，常用操作是取得一个整数中某一位或连续几位对应的int值
template <typename T1> //T1支持位操作的任何类型，一般是int/long long
struct BitOp
{
    //反转从pos开始，长度为len的区域
    inline T1 flip(T1 op, size_t pos, size_t len = 1)
    {
        return op ^ (((1 << len) - 1) << pos);
    }

    //取得从pos开始，长度为len区域对应的整数值
    inline T1 &set(T1 &op, size_t pos, int v, size_t len = 1)
    {
        int o = ((1 << len) - 1);
        return op = (op & (~(op << pos))) | ((v & o) << pos);
    }

    //取得从pos开始，长度为len区域对应的整数值
    inline int get(T1 op, size_t pos, size_t len = 1)
    {
        return (op >> pos) & ((1 << len) - 1);
    }

    //输出二进制表示
    ostream &outBits(ostream &os, T1 i)
    {
        if (i)
        {
            outBits(os, (i >> 1)) << (i & 1);
        }
        return os;
    }
};
//32位整数运算使用BitOp<long>调用，64位使用BitOp<long long>调用

/*




*/