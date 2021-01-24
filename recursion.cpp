#include <iostream>

using namespace std;

int build(int num1, int num2)
{
        if(num1 < num2)
        {
		cout << "num1 " << num1 << endl;	
                return  2 * build(num1 + 1, num2);
        }
}

int main()
{
        int num1, tempnum1, num2;
        cout << "Enter a number that you want to build " << endl;
        cin >> num1;
        tempnum1 = num1;
        cout << "Enter a number of times that you want to build this number(grows one integer at a time) " << endl;
        cin >> num2;
        int num3 = build(num1, num2);
	cout << "num1 equals " << num3 << " num2 equals " << num2 << endl;	
}
