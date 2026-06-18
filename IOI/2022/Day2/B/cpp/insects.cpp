#include "insects.h"
#include <bits/stdc++.h>
using namespace std;
const int N=2e3+100;
int l[N],r[N],ord[N];
vector<int> ans[N];
void move_inside1(int i)
{
  move_inside(ord[i]);
}
void move_outside1(int i)
{
  move_outside(ord[i]);
}
int min_cardinality(int n) {
  srand(time(0));
  for(int i=0;i<n;i++)ord[i]=i;
  random_shuffle(ord,ord+n);
  vector<int> cur,oth;
  for(int i=0;i<n;i++)
  {
    move_inside1(i);
    cur.push_back(i);
    if(press_button()>1)
    {
      cur.pop_back();
      oth.push_back(i);
      move_outside1(i);
      l[i]=-1;
      r[i]=cur.size()-1;
    }    
  }
  for(auto x:cur)move_outside1(x);
  for(auto x:oth)
  {
    ans[(l[x] + r[x]) / 2].push_back(x);
  }
  // cout<<cur.size()<<endl;
  if(cur.size()>((n+1)/2))
  {
    return 1;
  }

  // cur.size() < n/2

  // max call = n
  for(int i=0;i<11;i++)
  {
    for(int j=0;j<cur.size()-1;j++)
    {
      move_inside1(cur[j]);
      // cout<<"adding "<<cur[j]<<endl;
      for(auto x:ans[j])
      {
        move_inside1(x);
        // cout<<"checking "<<x<<endl;
        // cout << "count " << press_button() << endl;
        if (press_button() > 1)
        {
          r[x]=j;
        }
        else
        {
          l[x]=j;
        }
        if(l[x]+1<r[x])
          ans[(l[x] + r[x]) / 2].push_back(x);
        move_outside1(x);
      }
      ans[j].clear();
    }
    for (int j = 0; j < cur.size() - 1; j++)
    {
      move_outside1(cur[j]);
    }
  }
  map<int,int> cnt;
  for(auto x:cur)cnt[x]++;
  for(auto x:oth)
  {
    cnt[cur[r[x]]]++;
  }
  int mi=n+10;
  for(auto [y,c]:cnt)mi=min(mi,c);
  return mi;
}