#include<bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int main()
{
    int n, q;
    cin>>n;
    long sum = 0;
    for(int i = 0; i < n; i++) 
    {
        long x;
        cin>>x;
        sum = ((sum%mod) + (x%mod) + mod) % mod;  // "+ mod" is for making negative nos., positive
    }
    cin>>q;
    for(int i = 0; i < q; i++)
    {
        long x;
        cin>>x;
        sum = ((sum%mod) + (sum%mod) + mod) % mod;
        cout<<sum%mod<<endl;
    }
    return 0;
}