//泛型参数的使用
//很多算法都会在结构体中开辟一个数组，并且使用类似MAXSIZE的结构全局定义这个数组的大小，典型的如Dijkstra等算法
const int MAXSIZE;
struct Dijkstra
{
    int m, n, d[MAXSIZE], p[MAXSIZE];
    ...
};

//如果题目需要定义多个MAXSIZE变量，比较麻烦，解决办法是引入泛型参数
template <int MAXSIZE>
struct Dijkstra
{
    int n, m, d[MAXSIZE], p[MAXSIZE];
};

//使用时就可以指定不同MAXSIZE
Dijkstra<MAXK * MAXN> sd;
Dijkstra<MAXN> pd;
/*
泛型参数问题：
    模板的声明或定义只能在全局，命名空间或类范围内进行。即不能在局部范围，函数内进行，比如不能在main函数中声明或定义一个模板。

    模板分为两种，一种是类模板，一种是函数模板。

    使用模板的目的就是能够让程序员编写与类型无关的代码。比如编写了一个交换两个整型int 类型的swap函数，这个函数就只能实现int 型，
对double，字符这些类型无法实现，要实现这些类型的交换就要重新编写另一个swap函数。使用模板的目的就是要让这程序的实现与类型无关，
比如一个swap模板函数，即可以实现int 型，又可以实现double型的交换。模板可以应用于函数和类。

    函数模板格式：

    template <class 形参名，class 形参名，......> 返回类型 函数名(参数列表)
    {
        函数体
    }

    类模板和函数模板都是以template开始后接模板形参列表组成，模板形参不能为空，一但声明了类模板就可以用类模板的形参名声明类中的成员变量和成员函数，
即可以在类中使用内置类型的地方都可以使用模板形参名来声明。

    template<class T> class A{public: T a; T b; T hy(T c, T &d);};
    在类A中声明了两个类型为T的成员变量a和b，还声明了一个返回类型为T带两个参数类型为T的函数hy。 
    2、类模板对象的创建：比如一个模板类A，则使用类模板创建对象的方法为A<int> m;在类A后面跟上一个<>尖括号并在里面填上相应的类型，这样的话类A中凡是用到模板形参的地方都会被int 所代替。
当类模板有两个模板形参时创建对象的方法为A<int, double> m;类型之间用逗号隔开。
    3、对于类模板，模板形参的类型必须在类名后的尖括号中明确指定。比如A<2> m;用这种方法把模板形参设置为int是错误的（编译错误：error C2079: 'a' uses undefined class 'A<int>'），
类模板形参不存在实参推演的问题。也就是说不能把整型值2推演为int 型传递给模板形参。要把类模板形参调置为int 型必须这样指定A<int> m。
    4、在类模板外部定义成员函数的方法为：
    template<模板形参列表> 函数返回类型 类名<模板形参名>::函数名(参数列表){函数体}，
    比如有两个模板形参T1，T2的类A中含有一个void h()函数，则定义该函数的语法为：
    template<class T1,class T2> void A<T1,T2>::h(){}；
注意：当在类外面定义类的成员时template后面的模板形参应与要定义的类的模板形参一致。

https://www.runoob.com/w3cnote/c-templates-detail.html
*/