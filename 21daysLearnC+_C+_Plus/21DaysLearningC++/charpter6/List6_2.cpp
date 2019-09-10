//将字符串复制到 char 数组中之前，检查数组的容量

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
    cout << "Enter a line of text: " << endl;
    string userInput;
    getline(cin, userInput);

    char copyInput[20] = {'\0'};
    if (userInput.length() < 20) // check bounds
    {
        strcpy(copyInput, userInput.c_str());
        cout << "copyInput contains: " << copyInput << endl;
    }
    else
        cout << "Bounds exceeded: won't copy!" << endl;

    return 0;
}