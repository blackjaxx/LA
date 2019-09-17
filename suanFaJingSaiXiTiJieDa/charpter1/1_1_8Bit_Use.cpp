//位运算操作封装
//使用位向量表示集合或状态压缩时，常用操作是取得一个整数中某一位或连续几位对应的int值
template <typename T1> //T1支持位操作的任何类型，一般是int/long long
struct BitOp
{
    //反转从pos开始，长度为len的区域
    inline T1 flip(T1 op, size_t pos, size_t len = 1)
    {
        return op ^ (((1 << len) - 1) << pos); //？？？？？？？？？？？？？？？？？？
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
size_t的细节问题

    前言：使用size_t可能会提高代码的可移植性、有效性或者可读性，或许同时提高这三者。
    在标准C库中的许多函数使用的参数或者返回值都是表示的用字节表示的对象大小，比如说malloc(n) 函数的参数n指明了需要申请的空间大小，
还有memcpy(s1, s2, n)的最后一个参数，表明需要复制的内存大小，strlen(s)函数的返回值表明了以’\0’结尾的字符串的长度（不包括’\0’），其返回值并不是该字符串的实际长度，因为要去掉’\0’。
    或许你会认为这些参数或者返回值应该被申明为int类型（或者long或者unsigned），但是事实上并不是。
C标准中将他们定义为size_t。标准中记载malloc的申明应该出现在，定义为：

    void *malloc(size_t n);
    　　
    memcpy和strlen的声明应该出现在：

    void *memcpy(void *s1, void const *s2, size_t n);
    size_t strlen(char const *s);

    size_t还经常出现在C++标准库中，此外，C++库中经常会使用一个相似的类型size_type，用的可能比size_t还要多。
据我所知，大部分的C和C++程序员害怕这些库使用size_t，因为他们不知道size_t代表什么或者为什么这些库需要使用它，归根结底，原因在于他们什么时候什么地方需要用到它。

    可移植性问题：
    早期的C语言（由Brian Kernighan 和 Dennis Ritchie 在The C Programming Language书中所写，Prentice-Hall, 1978）并没有提供size_t类型，
C标准委员会为了解决移植性问题将size_t引入，举例如下：
    让我们来写一个可移植的标准memcpy函数，我们将会看到一些不同的申明和它们在不同平台不同大小的地址空间上编译下的情况。
    回忆memcpy(s1, s2, n)函数，它将s2指向地址开始的n个字节拷贝到s2指向的地址，返回s1，这个函数可以拷贝任何数据类型，所以参数和返回值的类型应该为可以指向任何类型的void*
同时，源地址不应该被改变，所以第二个参数s2类型应该为const void*，这些都不是问题。
    真正的问题在于我们如何申明第三个参数，它代表了源对象的大小，我相信大部分程序员都会选择int：
    void *memcpy(void *s1, void const *s2, int n);
    使用int类型在大部分情况下都是可以的，但是并不是所有情况下都可以。int是有符号的，它可以表示负数，但是，大小不可能是复数。所以我们可以使用unsigned int代替它让第三个参数表示的范围更大。
    在大部分机器上，unsigned int的最大值要比int的最大值大两倍，比如说再也给16位的机器上，unsigned int的最大值为65535，int的最大值为32767。
    尽管int类型的大小依赖于C编译器的实现，但是在给定的平台上int对象的大小和unsigned int对象的大小是一样的。
    因此，使用unsigned int修饰第三个参数的代价与int是相同的：

    void *memcpy(void *s1, void const *s2, unsigned int n);

    这样似乎没有问题了，unsigned int可以表示最大类型的对象大小了，这种情况只有在整形和指针类型具有相同大小的情况下，比如说在IP16中，整形和指针都占2个字节（16位），而在IP32上面，整形和指针都占4个字节（32位）。（参见下面C数据模型表示法）
    不幸的是，这种memcpy的申明在I16LP32架构上（整形是16-bit 长整形和指针类型时32-bits）显得不够用了，比如说摩托罗拉第一代处理器68000，在这种情况下，
处理器可能拷贝的数据大于65535个字节，但是这个函数第三个参数n不能处理这么大的数据。
    什么？你说很容易就可以改正？只需要把memcpy的第三个参数的类型修改一下：
    
    void *memcpy(void *s1, void const *s2, unsigned long  n); 　
    　
    你可以在I16LP32目标架构上使用这个函数了，它可以处理更大的数据。而且在IP16和IP32平台上效果也还行，说明它确实给出了memcpy的一种移植性较好的申明。但是，在IP16平台上相比于使用unsigned int，你使用unsigned long可能会使你的代码运行效率大打折扣（代码量变大而且运行变慢）。
    在标准C中规定，长整形（无论无符号或者有符号）至少占用32位，因此在IP16平台上支持标准C的话，那么它一定是IP16L32 平台。
这些平台通常使用一对16位的字来实现32位的长整形。在这种情况下，移动一个长整形需要两条机器指令，每条移动一个16位的块。
事实上，这个平台上的大部分的32位操作都需要至上两条指令。因此，以可移植性为名将memcpy的第三个参数申明为unsigned long而降低某些平台的性能是我们所不希望看到的。使用size_t可以有效避免这种情况。

    size_t类型是一个类型定义，通常将一些无符号的整形定义为size_t，比如说unsigned int或者unsigned long，甚至unsigned long long。
每一个标准C实现应该选择足够大的无符号整形来代表该平台上最大可能出现的对象大小。

    size_t的定义在<stddef.h>, <stdio.h>, <stdlib.h>, <string.h>, <time.h>和<wchar.h>这些标准C头文件中，也出现在相应的C++头文件, 等等中，你应该在你的头文件中至少包含一个这样的头文件在使用size_t之前。
    包含以上任何C头文件（由C或C++编译的程序）表明将size_t作为全局关键字。包含以上任何C++头文件（当你只能在C++中做某种操作时）表明将size_t作为std命名空间的成员。
    根据定义，size_t是sizeof关键字（注：sizeof是关键字，并非运算符）运算结果的类型。
    参数中带有size_t的函数通常会含有局部变量用来对数组的大小或者索引进行计算，在这种情况下，size_t是个不错的选择。
    适当地使用size_t还会使你的代码变得如同自带文档。当你看到一个对象声明为size_t类型，你马上就知道它代表字节大小或数组索引，而不是错误代码或者是一个普通的算术值。

作者：盛夏光年
链接：https://www.zhihu.com/question/24773728/answer/66535663
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/