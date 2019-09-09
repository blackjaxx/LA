//智能指针问题；
//STL还提供了另一个模板类：auto_ptr类。该类主要用于管理动态内存分配。
//auto_ptr模板定义了类似指针的对象，将new获得的地址赋给该对象。当auto_ptr对象过期时，析构函数将使用delete来释放内存。
//如果将new返回的地址赋值给auto_ptr对象，无须记住还需要释放这些内存。在auto_ptr对象过期时，内存将自动被释放。
//在C++语言中，要使用STL中的auto_ptr对象，必须包含头文件<memory>，该文件包括auto_ptr模板。使用通常的模板句法来实例化所需类型的指针。
//auto_ptr构造函数是显式的，不存在从指针到auto_ptr对象的隐式类型转换。

#include <memory>
using namespace std;

auto_ptr<double> pd;
//pd = p_reg; // 不允许
double *preg = new double;
pd = auto_ptr<double> (preg);
//auto_ptr<double> panto = preg; //不允许
auto_ptr<double> pauto(preg);
//模板可以通过构造函数将auto_ptr对象初始化为一个常规指针。auto_ptr是一个智能指针，但其特性远比指针要多。值得注意的是，在使用auto_ptr时，只能配对使用new和delete。