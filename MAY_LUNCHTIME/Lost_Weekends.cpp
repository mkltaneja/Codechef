#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int day[5];
        for(int i=0;i<5;i++)
            cin>>day[i];
        int p;
        cin>>p;
        int need = 0;
        int rem = 0;
        for(int i=0;i<5;i++)
        {
            // cout<<p*day[i]<<endl;
            if(p*day[i] - 24 > 0)
                need += (p*day[i] - 24);
            else 
                rem += (24 - p*day[i]);
            // cout<<need<<" "<<rem<<endl;
        }
        if(need > rem)
            cout<<"Yes\n";
        else 
            cout<<"No\n";
    }
    return 0;
}   