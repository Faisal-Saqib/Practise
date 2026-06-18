#include <bits/stdc++.h>
using namespace std;
const int N=1e6+100;
typedef long long ll;
ll l[N],r[N];
pair<ll,ll> sm[N][2];
bool ig(pair<ll,ll> a,pair<ll,ll> b)
{
    if(b.first==0)return 1;
    if(a.first==0)return 0;
    if(a.second>=b.second)
    {
        // a.first * 2^(a.second-b.second) >= b.first
        return (1ll << min(31ll, a.second - b.second)) * a.first >= b.first;
    }
    // a.first  >= b.first * 2^(b.second-a.second)
    return (1ll << min(31ll, b.second - a.second)) * b.first <= a.first;
}
void dfs(int x)
{
    if(l[x]>0)
    {
        dfs(l[x]);
        sm[x][0]=sm[l[x]][0];
        sm[x][0].second++;
    }
    else
    {
        sm[x][0]={-l[x],0};
    }
    
    if(r[x]>0)
    {
        dfs(r[x]);
        // we know sm[r[x]][0] == sm[r[x]][1]
        // we can make sm[x][1] = (sm[r[x]][0].first,sm[r[x][0].second+1)
        sm[x][1]=sm[r[x]][0];
        sm[x][1].second++;
    }
    else
    {
        sm[x][1]={-r[x],0};
    }
    // ll mx=max(sm[x][0],sm[x][1]);
    if(ig(sm[x][0],sm[x][1]))
    {
        // ig(x,y) return x>y
        sm[x][1]=sm[x][0];
    }
    else
    {
        sm[x][0]=sm[x][1];
    }
    
    // (x,p) = x * 2^p
    // how to add to such numbers
    // 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    dfs(1);
    ll cur=sm[1][0].first;
    for(int i=__lg(cur);i>=0;i--)
    {
        cout<<(bool)((cur>>i)&1);
    }
    for(int j=0;j<=sm[1][0].second;j++)cout<<0;
    cout<<endl;
}