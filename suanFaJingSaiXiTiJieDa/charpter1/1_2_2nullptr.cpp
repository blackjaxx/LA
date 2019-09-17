//nullptr
//c++11中表示空指针的数据类型nullptr
//以前的写法

char *p = NULL; //NULL只是定义长整数的宏
int i = NULL;

//c++11中
char *p = nullptr;
int i = nullptr; // 这里报错， nullptr不是整数类型
if (p)           //这里仍然可转换bool类型的false；
