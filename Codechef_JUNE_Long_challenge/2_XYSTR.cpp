#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int i = 0;
        int pairs = 0;
        while (i < s.size() - 1)
        {
            int x = pairs;
            pairs += (s[i + 1] != s[i]);
            i += (x < pairs) ? 2 : 1;
        }
        cout<<pairs<<endl;
    }
}