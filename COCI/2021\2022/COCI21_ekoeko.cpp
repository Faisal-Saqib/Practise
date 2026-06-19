#include <bits/stdc++.h>
using namespace std;
vector<int> oc[30];
const int N=2e5+100;
int fen[N],ind[N],ar[N];
bool fh[N];
void add(int x,int y=1)
{
    x++;
    while(x<N)
    {
        fen[x]+=y;
        x+=(x&-x);
    }
}
int qry(int x)
{
    x++;
    int ans=0;
    while(x)
    {
        ans+=fen[x];
        x-=(x&-x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<2*n;i++)
    {
        oc[s[i]-'a'].push_back(i);
    }
    int alr=0;
    for(int j=0;j<26;j++)
    {
        int sz=oc[j].size();
        for(int i=0;i<sz/2;i++){
            fh[oc[j][i]]=1;
        }
        oc[j].clear();
    }
    long long ans=0;    
    for(int i=0;i<2*n;i++)
    {
        if(fh[i])
        {
            ind[i]=alr++;
        }
    }
    for(int i=0;i<2*n;i++)
    {
        if(!fh[i])
        {
            ind[i]=alr++;
        }
    }
    // cout<<"IND: ";
    for(int i=0;i<2*n;i++)
    {
        // cout<<ind[i]<<' ';
        ans+=i-qry(ind[i]);
        add(ind[i]);
    }
    // cout<<endl;

    for(int i=0;i<2*n;i++)add(ind[i],-1);
    // cout<<ans<<endl;
    for(int i=0;i<2*n;i++)
    {
        oc[s[i]-'a'].push_back(ind[i]);
    }
    for(int j=0;j<26;j++)
    {
        int sz=oc[j].size();
        for(int i=0;i<sz/2;i++){
            ar[oc[j][i]]=oc[j][i+sz/2];
        }
        oc[j].clear();
    }
    for(int i=0;i<n;i++)
    {
        ans+=i-qry(ar[i]);
        add(ar[i]);
    }
    cout<<ans<<endl;
}