#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int q[n];
        for (int i = 0; i < n; i++)
            cin >> q[i];

        int m[3] = {0};
        bool f = true;
        for (int mon : q)
        {
            // cout<<mon/5<<endl;
            m[(mon/5)-1]++;
            if(mon == 5)
                continue;
            if(mon == 10 && m[0] < 1)
            {
                f = false;
                break;
            }
            else if (mon == 10 && m[0] > 0)
                m[0]--;
            else if(mon == 15 && (m[0] < 2 && m[1] < 1))
            {
                f = false;
                break;
            }
            else if(mon == 15)
            {
                if(m[1] >= 1)
                    m[1]--;
                else if(m[0] >= 2)
                    m[0] -= 2;
            }
        }
        if(f)
            cout << "Yes\n";
        else
            cout<<"No\n";
    }
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // your code goes here
    int t;
    bool flag;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        flag = true;
        vector<int> arr(n, 0);
        vector<int> count(3, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 5)
            {
                count[0]++;
            }
            else if (arr[i] == 10)
            {
                count[1]++;
                if (count[0] >= 1)
                    count[0]--;
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (arr[i] == 15)
            {
                count[2]++;
                if (count[0] >= 2)
                    count[0] -= 2;
                else if (count[1] >= 1)
                    count[1]--;
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}