/*
重载的 << 运算符

<<默认的含义是左移运算符
在ostream类重新定义了 << 运算符，叫做插入运算符
它能识别所有基本类型
unsigned char
signed char
char
short
unsigned shrot
int
unsigned int
long
unsigned long
long long (c++11)
unsigned long long (c++11)
float
double
long double

比如 cout << 88
方法原型是
ostream & operator << (int);
上边返回一个指向ostream对象的引用，这使得输出可以连接起来


ostream类还为下面指针类型定义了插入运算符函数
const signed char *;
const unsigned char *;
const char *;
void *;



*/