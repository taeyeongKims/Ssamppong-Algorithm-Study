#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() 
{
    int rep;
    cin >> rep;

    for (int i = 0; i < rep; i++)
    {
        string Order;
        cin >> Order;

        int size;
        cin >> size;

        deque<int> Numque;
        string str;
        cin >> str;

        string temp = "";
        for (int i = 1; i < str.size(); i++) 
        {
            if (isdigit(str[i])) {
                temp += str[i];
            }
            else if (str[i] == ',' || str[i] == ']') 
            {
                if (!temp.empty()) {
                    Numque.push_back(stoi(temp));
                    temp = "";
                }
            }
        }

        bool reversed = false;
        bool errorOccurred = false;

        // 명령 처리
        for (char currOrder : Order) 
        {
            if (currOrder == 'R')
            {
                reversed = !reversed;
            }
            else if (currOrder == 'D') 
            {
                if (Numque.empty()) 
                {
                    errorOccurred = true;
                    break;
                }
                if (reversed) 
                {
                    Numque.pop_back();
                }
                else 
                {
                    Numque.pop_front();
                }
            }
        }

        // 결과 출력
        if (errorOccurred) 
        {
            cout << "error\n";
        }
        else 
        {
            cout << "[";
            if (reversed)
            {
                for (int i = Numque.size() - 1; i >= 0; i--) 
                {
                    cout << Numque[i];
                    if (i != 0) 
                    {
                        cout << ",";
                    }
                }
            }
            else 
            {
                for (int i = 0; i < Numque.size(); i++) 
                {
                    cout << Numque[i];
                    if (i != Numque.size() - 1) 
                    {
                        cout << ",";
                    }
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}
