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