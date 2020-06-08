#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin>>s;
        int ans = 0;
        string t1 = "";
        string t2 = s;
        for(int i=2;i<=s.size()-2;i+=2)
        {
            // t1 += s[i-2];
            // t1 += s[i-1];
            // t2 = s.substr(i);
            // cout<<t1<<" "<<t2<<endl;
            bool f1 = true;
            for(int j = 0;j<i/2;j++)
            {
                // cout<<t1[j]<<" "<<t1[i/2+j]<<endl;
                // cout<<s[j]<<" "<<s[i/2+j]<<endl;
                if(s[j] != s[j+i/2])
                {
                    f1 = false;
                    break;
                }
            }
            // cout<<endl;
            bool f2 = true;
            for(int j = i;j<i+(s.size()-i)/2;j++)
            {
                // cout<<j<<" "<<(s.size()-i)/2+j<<endl;
                // cout<<s[j]<<" "<<s[(s.size()-i)/2+j]<<endl;
                if(s[j] != s[(s.size()-i)/2+j])
                {
                    f2 = false;
                    break;
                }
            }
            if(f1 && f2)
                ans++;
        }
        cout<<ans<<endl;
    }
}