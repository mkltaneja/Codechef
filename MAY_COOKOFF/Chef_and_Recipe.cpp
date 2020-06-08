#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        unordered_map<int, int> mc;
        unordered_map<int, bool> mb;
        int prev = arr[0];
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != prev)
            {
                mb[prev] = true;
                for (auto itr : mc)
                {
                    if (itr.first != prev && itr.second == mc[prev])
                    {
                        // cout << itr.first << " " << itr.second << endl;
                        cout << "NO\n";
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (mc.find(arr[i]) == mc.end())
            {
                mc.insert({arr[i], 1});
                mb.insert({arr[i], false});
            }
            else if (!mb[arr[i]])
            {
                mc.insert({arr[i], mc[arr[i]]++});
                mb.insert({arr[i], false});
            }
            else
            {
                cout << "NO\n";
                flag = false;
                break;
            }
            prev = arr[i];
        }

        if (flag)
        {
            for (auto itr : mc)
            {
                if (itr.first != prev && itr.second == mc[prev])
                {
                    // cout << itr.first << " " << itr.second << endl;
                    cout << "NO\n";
                    flag = false;
                    break;
                }
            }
        }
        if(flag)
            cout << "YES\n";

        // for(auto itr : mc)
        //     cout<<itr.first<<" "<<itr.second<<endl;
        // for(auto itr : mb)
        //     cout<<itr.first<<" "<<itr.second<<endl;
    }
}