#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define pii pair<int, int>
#define pib pair<int, bool>
#define pbi pair<bool, int>
#define pbb pair<bool, bool>
#define pic pair<int, char>
#define pci pair<char, int>
#define pcc pair<char, char>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define vi vector<int>
#define vvi vector<vi>
#define vd vector<double>
#define vvd vector<vd>
#define vll vector<ll>
#define vvll vector<vll>
#define vull vector<ull>
#define vvull vector<vull>
#define vb vector<bool>
#define vvb vector<vb>
#define vc vector<char>
#define vvc vector<vc>
#define vs vector<string>
#define vvs vector<vs>
#define vpii vector<pii>
#define vpbi vector<pbi>
#define vpib vector<pib>
#define vpbb vector<pbb>
#define vpci vector<pci>
#define vpic vector<pic>
#define vpcc vector<pcc>
#define vpsi vector<psi>
#define vpis vector<pis>
#define vpss vector<pss>
#define um unordered_map
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define umic unordered_map<int, char>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>
#define omii map<int, int>
#define omci map<char, int>
#define omic map<int, char>
#define omsi map<string, int>
#define omis map<int, string>
#define lp(i, a, b) for (int i = a; i < b; i++)
#define lpr(i, b, a) for (int i = b; i > a; i--)
#define lpl(i, a, b) for (ll i = a; i < b; i++)
#define lplr(i, b, a) for (ll i = b; i > a; i--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);}
#define mod 1000000007

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
ll binpowmod(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

bool ispal(string &a)
{
    for (int i = 0; i < a.size() / 2; i++)
        if (a[i] != a[a.size() - i - 1])
            return false;
    return true;
}

void display(int n, vi &a)
{
    for(int x : a) cout<<x<<" ";
    cout<<"\n";
}
void display(int n, int m, vvi &a)
{
    lp(i, 0, n)
    {
        lp(j, 0, m)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////MUKUL TANEJA///////////////////////////////////////////////////

int solve(int n, int m, string &ss)
{
    int j = 0;
    for(int i = 0; i < n && j < m; i++)
    {
        char x = (j % 26 + 'a');
        if(ss[i] == x) j++;
    }
    if(j < m) return -1;
    
    vi nxt(n,n);
    vi lc(26,n);
    vi a;
    int lim = log2(m) + 1;
    vvi dp(n+1, vi(lim+1, n));
    for(int i = n-1; i >= 0; i--)
    {
        int x = (ss[i]-'a'+1) % 26;
        nxt[i] = lc[x];
        dp[i][0] = nxt[i];
        lc[ss[i]-'a'] = i;
        if(ss[i] == 'a') a.pb(i);
    }
    
    for(int i = n-1; i >= 0; i--)
        for(int j = 1; j <= lim; j++)
            dp[i][j] = dp[dp[i][j-1]][j-1];

    // O(n^2) approach -> TLE
    int ans = INT_MAX;
    // for(int i : a)
    // {
    //     int k = 0, j = i;
    //     for(; nxt[j] != -1 && k < m-1; j=nxt[j], k++);
    //     // cout<<i<<" -> "<<j<<", "<<k<<endl;
    //     if(k == m-1) ans = min(ans, j-i+1-m);
    // }

    // O(n*logm) approach -> AC
    for(int i : a)
    {
        int j = i, depth = m-1;
        for(int k = lim; k >= 0 && depth && j != n; k--)
        {
            if(depth - (1 << k) >= 0)
            {
                j = dp[j][k];
                depth -= (1 << k);
            }
        }
        if(j == n) continue;
        // cout<<i<<", "<<j<<", "<<depth<<endl;
        ans = min(ans, j-i+1-m);
    }

    return ans == INT_MAX? -1 : ans;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin>>n;
        string ss;
        cin>>ss;
        cin>>m;

        cout<<solve(n, m, ss)<<endl;
    }
    return 0;
}