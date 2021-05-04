#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long n, w, r;
        cin>>n>>w>>r;
        vector<long> a(n);
        unordered_map<long,long> m;
        for(int i = 0; i < n; i++) cin>>a[i], m[a[i]]++;
        if(r >= w)
        {
            cout<<"YES\n";
            continue;
        }
        long sum = 0;
        for(auto p : m) 
            sum += p.first*(p.second/2);
        if(2*sum + r >= w) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}