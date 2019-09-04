#include <iostream>
using namespace std;

int main()
{
    cout << "Enter two integers: " << endl;
    int num1 = 0, num2 = 0;
    cin >> num1;
    cin >> num2;

    cout << "Enter \'m\' to multiply, anything else to add: ";
    char userSelection = '\0';
    cin >> userSelection;

    int result = 0;
    if (userSelection == 'm')
        result = num1 * num2;
    else
        result = num1 + num2;

    cout << "result is: " << result << endl;

    return 0;
}
//在 C++中，表达式的结果为 true 意味着不为 false，而 false 为零。因此，在条件语句中，
//只要表达式的结果不为零（负数或正数），就被视为结果为 true;

/*

if (condition)

{ 
 // condition success block 
 Statement 1; 
 Statement 2; 
}

else

{ 
 // condition failure block 
 Statement 3; 
 Statement 4; 
}


*/
