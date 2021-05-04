#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n, a, b;
        cin>>n>>a>>b;
        long long x = 0, y = 0;
        for(int i = 0; i < n; i++) 
        {
            string s;
            cin>>s;
            char c = s[0];
            if(c == 'E' || c == 'Q' || c == 'U' || c == 'I' || c == 'N' || c == 'O' || c == 'X')
                x += a;
            else y += b;
        }
        if(x > y) cout<<"SARTHAK\n";
        else if(x < y) cout<<"ANURADHA\n";
        else if(x == y) cout<<"DRAW\n";
    }
    return 0;
}