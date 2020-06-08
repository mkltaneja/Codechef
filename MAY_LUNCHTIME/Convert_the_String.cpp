#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        char minb='z',maxb='a';
        for(int i=0;i<n;i++)
        {
            minb = char(min(minb,b[i]));
            maxb = char(max(maxb,b[i]));
        }
        // cout<<minb<<" "<<maxb<<endl;
        bool f = false;
        for(int i=0;i<n;i++)
        {
            if(a[i] == minb)
            {
                f=true;
                break;
            }
        }
        if(!f)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<vector<int>> arr(0,vector<int>());
        int k = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i] >= 'b')
            {
                arr.resize(++k);
                arr[k].push_back(i);
            }
        }
    }
}
// PENDING