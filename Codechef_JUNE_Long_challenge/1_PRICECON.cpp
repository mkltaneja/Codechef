#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];
        int loss = 0;
        for (int pr : p)
            loss += (pr > k) ? (pr - k) : 0;
        cout << loss << endl;
    }
    return 0;
}