#include <iostream>
#include <string>
using namespace std;

bool isNumber(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

bool valid(string s)
{
    int sum = 0;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        int n = s[i] - '0';
        if (!(s.length() % 2 == 0 ^ i % 2 == 0))
        {
            n *= 2;
            if (n > 9)
                n = 1 + (n % 10);
        }
        sum += n;
    }   
    int last = s[s.length() - 1] - '0';
    int calcLast = 10 - (sum % 10);

    if (calcLast == last)
        return true;
    else
        return false;
}
int main(void)
{
    string ccnum;
    while (true)
    {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccnum;
        if (ccnum == "exit")
            break;

        if (!isNumber(ccnum))
            cout << "Bad Input" << endl;
        else if (valid(ccnum))
            cout << "Credit Card Number is valid" << endl;
        else
            cout << "Credit Card Number is not valid" << endl;
    }

    return 0;
}