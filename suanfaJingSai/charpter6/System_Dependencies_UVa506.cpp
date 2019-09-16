//系统依赖
//软件安装之间会有依赖关系，例如TELNET和FTP都依赖于TCP/,模拟安装和删除的过程
//首先是一些DEPEND指令，说明软件之间的依赖关系(不存在循环依赖),然后是一些INSTALL REMOVE LIST指令
//DEPEND item 1 item 2 [item 3]...   item1依赖于item2，item3...
//INSTALL item1 (已安装过的不用重新安装)显式安装，必须用remove指令显示删除
//REMOVE item1   卸载item1和它的依赖(如果某个组件还被其他显式安装的组件所依赖，则不能卸载这个软件)
//LIST   输出所有安装组件
//指令都是大写字母，每行指令不超过80字符，指令名称大小写敏感

//维护一个组件名字列表，这样可以把输入的组件名转化为整数编号
//接下来使用两个vector   depend[x]和depend2[x]，分别表示组件x所依赖的组件列表和依赖于x的组件列表
//即读到DEPEND x y时将y加入depend[x]  把x加入到depend2[y]
//为了区分显式安装和隐式安装，使用数组status[x],0表示组件x未安装，1表示隐式显式安装，2表示隐式安装

void install(int item, bool toplevel)
{
    if (!status[item])
    {
        for (int i = 0; i < depend[item].size(); i++)
        {
            install(depend[item][i], false);
        }
        cout << "  INSTALLING  " << name[item] << "\n";
        status[item] = toplevel ? 1 : 2;
        install.pushback(item);
    }
}