#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            char top = st.top();
            st.pop();
            if (ch == ')' && top != '(')
                return false;
            if (ch == ']' && top != '[')
                return false;
            if (ch == '}' && top != '{')
                return false;
        }
    }
    return st.empty();
}

int main(){
    string input;
    cout<<"Enter the input string:"<<endl;
    cin>>input;
    bool ans = isValid(input);
    string output = ans ? "true" : "false";
    cout<<output;
    return 0;
}
