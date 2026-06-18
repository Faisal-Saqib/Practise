#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=509,LG=20;
string g[N];
int dx[]={0,0,1,-1,+1,+1,-1,-1};
int dy[]={1,-1,0,0,+1,-1,+1,-1};
ll base=119,mod=1e9+7;
ll hsh[N][N][20];
ll pw[LG];
map<ll,ll> cnt;
ll n,m,k;
int anxt(int i,int d,int mv)
{
    return ((i+dx[d]%n*mv%n)%n+n)%n;
}
int bnxt(int j, int d, int mv)
{
    return ((j + dy[d]%m * mv %m) % m + m) % m;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    k=min(k,lcm(n,m));
    pw[0]=base;
    for(int i=1;i<LG;i++)
    {
        pw[i]= (pw[i-1]*pw[i-1]);
    }
    for(int i=0;i<n;i++)
    {
        cin>>g[i];
    }
    for(int d=0;d<8;d++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                hsh[i][j][0]=g[i][j]-'a'+1;
            }
        }
        for(int p=1;p<LG;p++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    hsh[i][j][p]=((hsh[i][j][p-1]*pw[p-1])+hsh[anxt(i,d,(1ll<<(p-1)))][bnxt(j,d,(1ll<<(p-1)))][p-1]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ll cur=0;
                int ci=i,cj=j;
                for(int p=LG-1;p>=0;p--)
                {
                    if((k>>p)&1)
                    {
                        cur=(cur*pw[p]);
                        cur=(cur+hsh[ci][cj][p]);
                        ci = anxt(ci, d, (1 << p));
                        cj = bnxt(cj, d, (1 << p));
                    }
                }
                cnt[cur]++;
            }
        }
    }
    ll tot=n*m*8;
    tot*=tot;
    ll sm=0;
    for(auto [s,c]:cnt)
        sm+=(c*c);
    ll g=__gcd(sm,tot);
    sm/=g;tot/=g;
    cout<<sm<<'/'<<tot<<endl;
}