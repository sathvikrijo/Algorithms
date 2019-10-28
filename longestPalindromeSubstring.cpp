#include<bits/stdc++.h>
using namespace std;

string getLPS(string input)
{
    string output = "";
    if(input.length() == 0)
        return output;
    
    int n = input.length();
    bool dp[n][n];

    for(int start=n-1; start>=0; start--)
    {
        for(int end=start; end<n; end++)
        {
            if(end - start + 1 < 2)
                dp[start][end] = (input[start] == input[end]);
            else
                dp[start][end] = (input[start] == input[end]) && dp[start+1][end-1];

            if(dp[start][end] && end-start+1 > output.length())
                output = input.substr(start, end-start+1);           
        }
    }
    return output;
}

int main()
{
    string input;
    cin>>input;
    cout<<getLPS(input);
    return 0;
}