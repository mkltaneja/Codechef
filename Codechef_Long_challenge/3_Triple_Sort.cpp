#include <iostream>
#include <vector>
using namespace std;

void right_shift(int i1, int i2, int i3, vector<int> &arr)
{
    int v1 = arr[i1];
    int v2 = arr[i2];
    int v3 = arr[i3];

    arr[i2] = v1;
    arr[i3] = v2;
    arr[i1] = v3;

    // for (int i = 1; i < arr.size(); i++)
    //     cout << arr[i] << "   ";
    // cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n + 1, 0);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        int tu = 0;
        for (int i = 1; i <= n; i++)
            if (arr[i] != i)
                tu++;

        int count = 0;
        vector<vector<int>> patterns(k, vector<int>(3, 0));
        for (int i = 1; i <= n; i++)
        {
            if (tu == 0)
            {
                cout << count << endl;
                for (int j = 0; j < count; j++)
                {
                    for (int a = 0; a < patterns[j].size(); a++)
                        cout << patterns[j][a] << " ";
                    cout << endl;
                }
                break;
            }

            if (count == k)
            {
                cout << -1 << endl;
                break;
            }

            if (tu < 3)
            {
                cout << -1 << endl;
                break;
            }

            if (arr[i] == i)
                continue;

            int i1 = i;
            int i2 = arr[i1];
            if (arr[i2] == i1) //MIRROR CASE
            {
                int i3 = i + 1;
                while (arr[i3] == i3 || i3 == i2)
                    i3++;
                // cout << i1 << " " << i3 << " " << i2 << endl;
                patterns[count][0] = i1; //mark
                patterns[count][1] = i3; //
                patterns[count][2] = i2; //
                count++;
                tu--;
                right_shift(i1, i3, i2, arr);

                // for (int i = 1; i <= n; i++)
                //     cout << arr[i] << " ";
                // cout << endl;
            }
            else
            {
                int i3 = arr[i2];               //CYCLE CASE
                bool flag = false;
                while (arr[i3] != i1)           //NON-CYCLE CASE
                {
                    flag = true;
                    i3 = arr[i3];
                }
                // cout << i1 << " " << i2 << " " << i3 << endl;
                patterns[count][0] = i1; //mark
                patterns[count][1] = i2;
                patterns[count][2] = i3;
                count++;
                if (flag)
                    tu -= 2;
                else
                    tu -= 3;
                right_shift(i1, i2, i3, arr);

                // for (int i = 1; i <= n; i++)
                //     cout << arr[i] << " ";
            }
        }
    }
    // your code goes here
    return 0;
}
