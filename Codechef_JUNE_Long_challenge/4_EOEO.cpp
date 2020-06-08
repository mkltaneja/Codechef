#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int ts;
        cin >> ts;
        if(!((ts)&(ts-1)))
        {
            cout<<0<<endl;
            continue;
        }
        if(ts & 1)
        {
            cout<<ts/2<<endl;
            continue;
        }
        int count2 = 1;
        long long int n = ts;
        while(!(n&1))
        {
            count2++;
            n >>= 1;
        }

        long long int num = (1<<count2);
        cout<<ts/num<<endl;
    }
    return 0;
}