#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<int,int> p[1009];
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            bool pos=0;
            for(int k=j+1;k<n;k++)
            {
                for(int l=k+1;l<n;l++)
                {
                    // m1 = (p[j].y-p[i].y) / (p[j].x-p[i].x) 
                    // m2 = (p[k].y-p[l].y) / (p[k].x-p[l].x) 
                    // c1 = p[i].y - m1*p[i].x
                    // c2 = p[k].y - m2*p[k].x
                    // x*m1 + c1  = x*m2 + c2
                    // x = (c2-c1)/(m1-m2)
                    
                }
            }
            ans+=!pos;
        }
    }
    cout<<ans<<endl;
}