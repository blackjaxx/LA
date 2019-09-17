//一般都是使用g++进行编译然后命令行运行，每次都要输入大量繁琐命令
//使用win开发脚本
//1.编译脚本(ojc.bat) 这里假设ojc.bat和g++.exe 目录已经加入系统path中
/*

cls
g++ "%l" -lm -O2 -pipe -o"%~n1.exe"

使用方法如下
ojc UVa100.cc

//2.编译且直接运行(ojr.bat)  这里假设ojc.bat和g++.exe 目录已经加入系统path中

cls
echo 编译
del %~n1.exe
@g++ "%l" -lm -O2 -pipe -o"%~n1.exe"
@%~n1.exe<%~n1.in

以下命令会直接编译原文件
ojr UVa100.cc

*/