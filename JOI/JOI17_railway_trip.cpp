#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int l[N],dist[N],dp[N][2];
vector<int> ma[N],ind[N];
int n,k,q;
void bfs(int s)
{
    for(int i=1;i<=n;i++)dist[i]=1e9;
    queue<int> pq;
    pq.push(s);
    dist[s]=0;
    while(pq.size())
    {
        int x=pq.front();
        pq.pop();
        for(auto y:ma[x])
        {
            if(dist[y]==1e9)
            {
                dist[y]=dist[x]+1;
                pq.push(y);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>k>>q;
    int cc=0;
    for(int i=1;i<=n;i++)cin>>l[i],ind[l[i]].push_back(i),cc+=(l[i]==k);
    set<int> cur;
    for(int j=k;j>=1;j--)
    {
        for(auto i:ind[j])
        {
            cur.insert(i);
        }
        for(auto i:ind[j])
        {
            auto it=cur.upper_bound(i);
            if(it!=end(cur))
            {
                ma[*it].push_back(i);
                ma[i].push_back(*it);
            }
            it--;
            if(it!=begin(cur))
            {
                it--;
                ma[*it].push_back(i);
                ma[i].push_back(*it);
            }
        }
    }
    bfs(1);
    for(int i=1;i<=n;i++)dp[i][0]=dist[i];
    bfs(n);
    for(int i=1;i<=n;i++)dp[i][1]=dist[i];
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        bfs(a);
        cout<<min({b-a-1,dp[a][0]+dp[b][0],dp[a][1]+dp[b][1],dp[a][1]+dp[b][0]+cc,cc+dp[a][0]+dp[b][1]})<<endl;
    }
}