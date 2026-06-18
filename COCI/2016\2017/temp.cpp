#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 509;
string g[N];
int dx[] = {0, 0, 1, -1, +1, +1, -1, -1};
int dy[] = {1, -1, 0, 0, +1, -1, +1, -1};
map<int, ll> cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    k = min(k, lcm(n, m));
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    ll mod = 1e9 + 7, base = 119;
    ll mod1 = 998244353, base1 = 117;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int d = 0; d < 8; d++)
            {
                ll hsh = 0;
                // ll hsh1=0;
                for (int p = 0; p < k; p++)
                {
                    // cur+=g[i][j];
                    // hsh1 = (hsh1 * base1 + (g[i][j] - 'a' + 1)) % mod1;
                    cout<<g[i][j]-'a'+1<<' '<<i<<' '<<j<<' '<<hsh<<endl;
                    hsh = (hsh * base + (g[i][j] - 'a' + 1)) % mod;
                    i = (i + n + dx[d]) % n;
                    j = (j + m + dy[d]) % m;
                }
                cnt[hsh]++;
                // if(i==0 and j==0 and d==0)
                {

                    cout<<"for "<<i<<' '<<j<<' '<<d<<' '<<hsh<<endl;
                }
                return 0;
                // cnt[{hsh,hsh1}]++;
            }
        }
    }
    ll tot = n * m * 8;
    tot *= tot;
    ll sm = 0;
    for (auto [s, c] : cnt)
    {
        sm += (c * c);
    }
    ll g = __gcd(sm, tot);
    sm /= g;
    tot /= g;
    cout << sm << '/' << tot << endl;
}