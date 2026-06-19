#include <bits/stdc++.h>
using namespace std;
int cnt[1009][1009];
int cur[1009],deg[1009];
vector<int> ma[1009];
bool vis[1009],in[1009],a[1009],b[1009];
bool dfs(int x,int p=0)
{
    vis[x]=in[x]=1;
    bool cur=0;
    for(auto y:ma[x])
    {
        if(y^p)
        {
            if(!vis[y])
            {
                cur|=dfs(y,x);
            }
            else if(in[y])
            {
                cur=1;
            }
        }
    }
    in[x]=0;
    return cur;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        ma[x].push_back(y);
        ma[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    vector<int> op;
    for(int i=1;i<=n;i++)
    {
        a[i]=1;
    }
    for(int j=1;j<=5*n;j++)
    {
        int mx=-1,vj=-1;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==1 and deg[j]>mx)
            {
                mx=deg[j];
                vj=j;
            }
        }

        if(vj==-1)
        {
            cout<<"YES"<<endl;
            cout<<op.size()<<endl;
            for(auto x:op)cout<<x<<' ';
            cout<<endl;
            return 0;
        }
        op.push_back(vj);
        a[vj]=0;
        for(int j=1;j<=n;j++)
        {
            b[j]=0;
            for(auto i:ma[j])
            {
                b[j]|=a[i];
            }
        }
        for(int j=1;j<=n;j++)
        {
            a[j]=b[j];
        }
    }
    cout<<"NO"<<endl;
}