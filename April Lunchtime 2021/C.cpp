#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x = 0, y = 0;
        for(char c : s) 
        {
            if(c=='1') x++;
            else y++;
        }
        bool fl = false;
        if(x >= y) fl = true;
        int i = n-1;
        // cout<<x<<" "<<y<<endl;
        while((i >= 0) && !fl)
        {
            if(s[i] == '1') x--;
            else y--;
            // cout<<s[i]<<"; ";
            if(x >= y && x != 0) fl = true;
            i--;
            // cout<<x<<" "<<y<<endl;
        }
        // cout<<endl;
        if(fl) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}