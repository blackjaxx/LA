/*
在枚举复杂对象之前， 先尝试着枚举一些相对简单的内容， 如整数、 子串等。 尽管暴力
枚举不用太动脑筋， 但对问题进行一定的分析往往会让算法更加简洁、 高效;
 */

/*

输入正整数n， 按从小到大的顺序输出所有形如abcde/fghij = n的表达式， 其中a～ j恰好
为数字0～ 9的一个排列（ 可以有前导0） ， 2≤n≤79。

样例输入：

62

样例输出：

79546 / 01283 = 62
94736 / 01528 = 62

 */

/*
枚举0～ 9的所有排列？ 没这个必要。 只需要枚举fghij就可以算出abcde， 然后判断是否
所有数字都不相同即可。 不仅程序简单， 而且枚举量也从10!=3628800降低至不到1万， 而且
当abcde和fghij加起来超过10位时可以终止枚举。 由此可见， 即使采用暴力枚举， 也是需要认
真分析问题的。

 */

//Division, UVa 725
//程序