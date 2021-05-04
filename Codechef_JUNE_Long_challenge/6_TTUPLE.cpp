#include <iostream>
#include <vector>
# define vi vector<int>
using namespace std;

int countzero(vi &df)
{
    int count = 0;
    for(int i : df)
        if(i == 0)
            count++;
    return count;
}

int countsame(vi &df)
{
    int count = 0;
    if(df[0] == df[1] && df[0] == df[2])
        count = 3;
    else if(df[0] == df[1] || df[0] == df[2] || df[1] == df[2])
        count = 2;
    return count;
}

int count_bysum_p(vi &df)
{
    int zeroes = countzero(df);
    int nos = 3 - zeroes;
    int same = countsame(df);
    int uni = 3 - same;

    if(zeroes == 3)
        return 0;
    if(zeroes == 2)
        return 1;
    if(zeroes == 1 && same == 2)
        return 1;
    if(zeroes == 1 && same == 0)
        return 2;
    
    if(same == 3)
        return 1;
    if(same == 2)
        return 2;
    if(same == 0)
    {
        if(df[0] == abs(df[2]-df[1]) || df[1] == abs(df[0]-df[2]) || df[2] == abs(df[0]-df[1]))
            return 2;
        else 
            return 3;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vi p(3,0),a(3,0);
        for(int i=0;i<3;i++)
            cin>>p[i];
        for(int i=0;i<3;i++)
            cin>>a[i];
        vi df(3,0);
        vi dv(3,0);

        bool f = true;
        int negp = 0;
        int negm = 0;
        for(int i=0;i<3;i++)
        {
            df[i] = (a[i]-p[i]);
            if(df[i] < 0)
                negp++;
            if(float(a[i]/p[i]) != a[i]/p[i])
                f = false;
            if(a[i]/p[i] < 0)
                negm++;
            dv[i] = a[i]/p[i];
        }
        // if(negp > 0)
        //     count_bysum_n(df,negp);
        // else 
            cout<<count_bysum_p(df);
    }
}