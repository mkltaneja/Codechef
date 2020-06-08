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
        int arr[n][n] = {0};
        if (n & 1)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    arr[i][j] = ((i * n) + (j + 1));
        }
        else
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i & 1)
                        if (j & 1)
                            arr[i][j] = ((i * n) + (j));
                        else
                            arr[i][j] = ((i * n) + (j + 2));
                    else
                        arr[i][j] = ((i * n) + (j + 1));
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
}