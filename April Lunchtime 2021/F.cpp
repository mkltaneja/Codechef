#include<bits/stdc++.h>
using namespace std;

// bool res = false;
int finddist(int s, int d, vector<vector<int>> &gp, vector<bool> &vis)
{
    static int ans = -1;
    vis[s] = true;
    if(s == d) return 0;
    // {
    //     ans = dist;
    //     return ans;
    // }

    // int dist = 0;
    for(int v : gp[s])
    {
        if(!vis[v])
        {
            ans = finddist(v, d, gp, vis);
            if(ans != -1)
                return ans+1;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k, a;
        cin>>n>>k>>a;
        vector<int> f(k);
        for(int i = 0; i < k; i++) cin>>f[i];
        vector<vector<int>> gp(n);
        for(int i = 0; i < n-1; i++) 
        {
            int x, y;
            cin>>x>>y;
            gp[x-1].push_back(y-1);
            gp[y-1].push_back(x-1);
        }
        // for(int i = 0; i < n; i++) 
        // {
        //     cout<<i<<" -> ";
        //     for(int j = 0; j < gp[i].size(); j++)
        //         cout<<gp[i][j]<<" ";
        //     cout<<endl;
        // }

        map<pair<int,int>, int> dist;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                vector<bool> vis(n, false);
                // int d = 0;
                int d = finddist(i, j, gp, vis);
                dist.insert({{i, j}, d});
                // cout<<i<<", "<<j<<" --> "<<d<<endl;
            }
        }
        cout<<endl;
        vector<int> ans1(n), ans2(n);
        for(int i = 0; i < n; i++)
        {
            int mx = INT_MIN, sp = f[0];
            for(int j = 0; j < k; j++)
            {
                int au = dist[{min(a-1,f[j]-1), max(a-1,f[j]-1)}];
                int bu = dist[{min(i,f[j]-1), max(i,f[j]-1)}];
                // cout<<min(a-1, f[j]-1)<<", "<<max(a-1, f[j]-1)<<" -> "<<au<<endl;
                // cout<<min(i, f[j]-1)<<", "<<max(i, f[j]-1)<<" -> "<<bu<<endl;
                if(au - bu > mx)
                {
                    mx = au-bu;
                    sp = f[j];
                }
            }
            ans1[i] = mx;
            ans2[i] = sp;
        }
        for(int i = 0; i < n; i++) cout<<ans1[i]<<" ";
        cout<<"\n";
        for(int i = 0; i < n; i++) cout<<ans2[i]<<" ";
        cout<<"\n";
    }
    return 0;
}