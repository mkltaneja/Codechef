#include <iostream>
using namespace std;

int main()
{
    long int t;
    cin >> t;
    while (t--)
    {
        long long int n, q;
        string s;
        cin >> n >> q >> s;
        long long int count[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
        }
        long long int maxi = count[0];
        for (int i = 1; i < 26; i++)
        {
            maxi = max(maxi, count[i]);
        }
        
        while (q--)
        {
            long long int c;
            cin >> c;
            
            long long int more = 0, sum = 0;
            if (c >= maxi)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    if (count[i] > c)
                    {
                        sum += count[i];
                        more++;
                    }
                }
            }
            cout << (sum - (more * c)) << endl;
        }
    }
    return 0;
}