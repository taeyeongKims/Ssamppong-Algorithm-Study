#include <iostream>
#include <string>
#include <stack>

// ют╥б ╫ц╧З 
using namespace std;

int main()
{
    while (true)
    {
        string input;
        getline(cin, input);

        if (input == ".")
        {
            break;
        }

        stack<char> stk;
        bool Balanced = 0;

        for (int i = 0; i < input.size(); i++)
        {
            char c = input[i];

            if ((c == '(') || (c == '['))
            {
                stk.push(c);
            }
            else if (c == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    Balanced = 1;
                    break;
                }
            }
            else if (c == ']')
            {
                if (!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    Balanced = 1;
                    break;
                }
            }
        }

        if (Balanced == 0)
        {
            cout << "yes" << endl;
        }
        else if (stk.empty())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }

    }

}
