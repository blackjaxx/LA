/*
    static_assert 是 C++11 新增的一项功能，让您能够在不满足指定条件时禁止编译。这好像不可思议，
但对模板类来说很有用。例如，您可能想禁止针对 int 实例化模板类，为此可使用 static_assert，它是一
种编译阶段断言，可用于在开发环境（或控制台中）显示一条自定义消息
    static_assert(expression being validated, "Error message when check fails");
*/

//一个挑剔的模板类，它使用 static_assert 在您针对 int 类型实例化时发出抗议
template <typename T> 
class EverythingButInt 
{ 
    public: 
        EverythingButInt() 
            { 
                static_assert(sizeof(T) != sizeof(int), "No int please!"); 
            } 
}; 

int main() 
{ 
    EverythingButInt<int> test; // template instantiation with int. 
    return 0; 
}
//编译器发出的抗议是在第 6 行指定的。static_assert 是 C++11 新增的一项功能，让您能够禁止不希望的模板实例化

//编写模板函数和模板类时，别忘了尽可能使用const