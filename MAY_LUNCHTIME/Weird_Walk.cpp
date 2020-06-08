#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        vector<long long int> a(n,0);
        for(int i=0;i<n;i++)
            cin>>a[i];

        vector<long long int> b(n,0);
        for(int i=0;i<n;i++)
            cin>>b[i];
        
        long long int d1 = 0;
        long long int d2 = 0;
        long long int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(d1 == d2 && a[i] == b[i])
                ans += a[i];
            d1 += a[i];
            d2 += b[i];
        }
        cout<<ans<<endl;
    }
}